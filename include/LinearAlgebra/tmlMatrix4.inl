
template<typename T>
inline T atMatrixDet2x2(T a, T b, T c, T d)
{
  return
    (a * d) -
    (b * c);
}

template<typename T>
inline T atMatrixDet3x3(T a, T b, T c, T d, T e, T f, T g, T h, T i)
{
  return
    a * atMatrixDet2x2(e, f, h, i) -
    b * atMatrixDet2x2(d, f, g, i) +
    c * atMatrixDet2x2(d, e, g, h);
}

template<typename T>
tmlMatrix4<T>::tmlMatrix4(const tmlMatrix4<T> &copy)
{
  memcpy(&m, &copy.m, sizeof(T) * 16);
}

template<typename T>
inline tmlMatrix4<T>::tmlMatrix4(T _00, T _01, T _02, T _03, T _10, T _11, T _12, T _13, T _20, T _21, T _22, T _23, T _30, T _31, T _32, T _33)
{
  m[0] = _00;  m[1] = _01;  m[2] = _02;  m[3] = _03;
  m[4] = _10;  m[5] = _11;  m[6] = _12;  m[7] = _13;
  m[8] = _20;  m[9] = _21;  m[10] = _22; m[11] = _23;
  m[12] = _30; m[13] = _31; m[14] = _32; m[15] = _33;
}

template<typename T>
inline tmlMatrix4<T>::tmlMatrix4(tmlMatrix4<T> &&move)
{
  memcpy(&m, &move.m, sizeof(m));
  move = Identity();
}

template<typename T>
template<typename T2>
inline const tmlMatrix4<T>& tmlMatrix4<T>::operator=(const tmlMatrix4<T2> &copy)
{
  for (int64_t i = 0; i < 16; ++i)
    m[i] = (T)copy[i];
  return *this;
}

template<typename T>
inline tmlMatrix4<T> tmlMatrix4<T>::Identity()
{
  return tmlMatrix4<T>(
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1);
}

template<typename T>
inline tmlMatrix4<T> tmlMatrix4<T>::Transpose() const
{
  return tmlMatrix4<T>(
    m[0], m[4], m[8], m[12],
    m[1], m[5], m[9], m[13],
    m[2], m[6], m[10], m[14],
    m[3], m[7], m[11], m[15]);
}

template<typename T>
inline tmlMatrix4<T> tmlMatrix4<T>::Cofactors() const
{
  return tmlMatrix4<T>(
    atMatrixDet3x3(m[5], m[6], m[7], m[9], m[10], m[11], m[13], m[14], m[15]),
    -atMatrixDet3x3(m[4], m[6], m[7], m[8], m[10], m[11], m[12], m[14], m[15]),
    atMatrixDet3x3(m[4], m[5], m[7], m[8], m[9], m[11], m[12], m[13], m[15]),
    -atMatrixDet3x3(m[4], m[5], m[6], m[8], m[9], m[10], m[12], m[13], m[14]),

    -atMatrixDet3x3(m[1], m[2], m[3], m[9], m[10], m[11], m[13], m[14], m[15]),
    atMatrixDet3x3(m[0], m[2], m[3], m[8], m[10], m[11], m[12], m[14], m[15]),
    -atMatrixDet3x3(m[0], m[1], m[3], m[8], m[9], m[11], m[12], m[13], m[15]),
    atMatrixDet3x3(m[0], m[1], m[2], m[8], m[9], m[10], m[12], m[13], m[14]),

    atMatrixDet3x3(m[1], m[2], m[3], m[5], m[6], m[7], m[13], m[14], m[15]),
    -atMatrixDet3x3(m[0], m[2], m[3], m[4], m[6], m[7], m[12], m[14], m[15]),
    atMatrixDet3x3(m[0], m[1], m[3], m[4], m[5], m[7], m[12], m[13], m[15]),
    -atMatrixDet3x3(m[0], m[1], m[2], m[4], m[5], m[6], m[12], m[13], m[14]),

    -atMatrixDet3x3(m[1], m[2], m[3], m[5], m[6], m[7], m[9], m[10], m[11]),
    atMatrixDet3x3(m[0], m[2], m[3], m[4], m[6], m[7], m[8], m[10], m[11]),
    -atMatrixDet3x3(m[0], m[1], m[3], m[4], m[5], m[7], m[8], m[9], m[11]),
    atMatrixDet3x3(m[0], m[1], m[2], m[4], m[5], m[6], m[8], m[9], m[10])
    );
}

template<typename T>
inline T tmlMatrix4<T>::Determinate() const
{
  return
    m[0] * atMatrixDet3x3(m[5], m[6], m[7], m[9], m[10], m[11], m[13], m[14], m[15])
    - m[1] * atMatrixDet3x3(m[4], m[6], m[7], m[8], m[10], m[11], m[12], m[14], m[15])
    + m[2] * atMatrixDet3x3(m[4], m[5], m[7], m[8], m[9], m[11], m[12], m[13], m[15])
    - m[3] * atMatrixDet3x3(m[4], m[5], m[6], m[8], m[9], m[10], m[12], m[13], m[14]);
}

template<typename T>
inline tmlMatrix4<T> tmlMatrix4<T>::Mul(const tmlMatrix4<T> &rhs) const
{
  return tmlMatrix4<T>(
    m[0] * rhs.m[0] + m[1] * rhs.m[4] + m[2] * rhs.m[8] + m[3] * rhs.m[12],
    m[0] * rhs.m[1] + m[1] * rhs.m[5] + m[2] * rhs.m[9] + m[3] * rhs.m[13],
    m[0] * rhs.m[2] + m[1] * rhs.m[6] + m[2] * rhs.m[10] + m[3] * rhs.m[14],
    m[0] * rhs.m[3] + m[1] * rhs.m[7] + m[2] * rhs.m[11] + m[3] * rhs.m[15],

    m[4] * rhs.m[0] + m[5] * rhs.m[4] + m[6] * rhs.m[8] + m[7] * rhs.m[12],
    m[4] * rhs.m[1] + m[5] * rhs.m[5] + m[6] * rhs.m[9] + m[7] * rhs.m[13],
    m[4] * rhs.m[2] + m[5] * rhs.m[6] + m[6] * rhs.m[10] + m[7] * rhs.m[14],
    m[4] * rhs.m[3] + m[5] * rhs.m[7] + m[6] * rhs.m[11] + m[7] * rhs.m[15],

    m[8] * rhs.m[0] + m[9] * rhs.m[4] + m[10] * rhs.m[8] + m[11] * rhs.m[12],
    m[8] * rhs.m[1] + m[9] * rhs.m[5] + m[10] * rhs.m[9] + m[11] * rhs.m[13],
    m[8] * rhs.m[2] + m[9] * rhs.m[6] + m[10] * rhs.m[10] + m[11] * rhs.m[14],
    m[8] * rhs.m[3] + m[9] * rhs.m[7] + m[10] * rhs.m[11] + m[11] * rhs.m[15],

    m[12] * rhs.m[0] + m[13] * rhs.m[4] + m[14] * rhs.m[8] + m[15] * rhs.m[12],
    m[12] * rhs.m[1] + m[13] * rhs.m[5] + m[14] * rhs.m[9] + m[15] * rhs.m[13],
    m[12] * rhs.m[2] + m[13] * rhs.m[6] + m[14] * rhs.m[10] + m[15] * rhs.m[14],
    m[12] * rhs.m[3] + m[13] * rhs.m[7] + m[14] * rhs.m[11] + m[15] * rhs.m[15]
    );
}

template<typename T>
inline tmlVector4<T> tmlMatrix4<T>::Mul(const tmlVector4<T> &rhs) const
{
  return tmlVector4<T>(
    rhs.x * m[0] + rhs.y * m[1] + rhs.z * m[2] + rhs.w *  m[3],
    rhs.x * m[4] + rhs.y * m[5] + rhs.z * m[6] + rhs.w *  m[7],
    rhs.x * m[8] + rhs.y * m[9] + rhs.z * m[10] + rhs.w * m[11],
    rhs.x * m[12] + rhs.y * m[13] + rhs.z * m[14] + rhs.w * m[15]
    );
}

template<typename T>
inline tmlMatrix4<T> tmlMatrix4<T>::Apply(T(*func)(const T &)) const
{
  tmlMatrix4<T> ret = *this;
  for (T &val : ret.m)
    val = func(val);
  return ret;
}

template<typename T>
template<typename T2>
inline tmlMatrix4<T> tmlMatrix4<T>::Mul(const tmlMatrix4<T2> &rhs) const
{
  return tmlMatrix4<T>(
    m[0] * (T)rhs.m[0] + m[1] * (T)rhs.m[4] + m[2] * (T)rhs.m[8] + m[3] * (T)rhs.m[12],
    m[0] * (T)rhs.m[1] + m[1] * (T)rhs.m[5] + m[2] * (T)rhs.m[9] + m[3] * (T)rhs.m[13],
    m[0] * (T)rhs.m[2] + m[1] * (T)rhs.m[6] + m[2] * (T)rhs.m[10] + m[3] * (T)rhs.m[14],
    m[0] * (T)rhs.m[3] + m[1] * (T)rhs.m[7] + m[2] * (T)rhs.m[11] + m[3] * (T)rhs.m[15],

    m[4] * (T)rhs.m[0] + m[5] * (T)rhs.m[4] + m[6] * (T)rhs.m[8] + m[7] * (T)rhs.m[12],
    m[4] * (T)rhs.m[1] + m[5] * (T)rhs.m[5] + m[6] * (T)rhs.m[9] + m[7] * (T)rhs.m[13],
    m[4] * (T)rhs.m[2] + m[5] * (T)rhs.m[6] + m[6] * (T)rhs.m[10] + m[7] * (T)rhs.m[14],
    m[4] * (T)rhs.m[3] + m[5] * (T)rhs.m[7] + m[6] * (T)rhs.m[11] + m[7] * (T)rhs.m[15],

    m[8] * (T)rhs.m[0] + m[9] * (T)rhs.m[4] + m[10] * (T)rhs.m[8] + m[11] * (T)rhs.m[12],
    m[8] * (T)rhs.m[1] + m[9] * (T)rhs.m[5] + m[10] * (T)rhs.m[9] + m[11] * (T)rhs.m[13],
    m[8] * (T)rhs.m[2] + m[9] * (T)rhs.m[6] + m[10] * (T)rhs.m[10] + m[12] * (T)rhs.m[14],
    m[8] * (T)rhs.m[3] + m[9] * (T)rhs.m[7] + m[10] * (T)rhs.m[11] + m[12] * (T)rhs.m[15],

    m[12] * (T)rhs.m[0] + m[13] * (T)rhs.m[4] + m[14] * (T)rhs.m[8] + m[15] * (T)rhs.m[12],
    m[12] * (T)rhs.m[1] + m[13] * (T)rhs.m[5] + m[14] * (T)rhs.m[9] + m[15] * (T)rhs.m[13],
    m[12] * (T)rhs.m[2] + m[13] * (T)rhs.m[6] + m[14] * (T)rhs.m[10] + m[15] * (T)rhs.m[14],
    m[12] * (T)rhs.m[3] + m[13] * (T)rhs.m[7] + m[14] * (T)rhs.m[11] + m[15] * (T)rhs.m[15]);
}

template<typename T>
template<typename T2>
inline tmlMatrix4<T> tmlMatrix4<T>::Add(const tmlMatrix4<T2> &rhs) const
{
  return tmlMatrix4<T>(
    m[0] + (T)rhs.m[0],
    m[1] + (T)rhs.m[1],
    m[2] + (T)rhs.m[2],
    m[3] + (T)rhs.m[3],
    m[4] + (T)rhs.m[4],
    m[5] + (T)rhs.m[5],
    m[6] + (T)rhs.m[6],
    m[7] + (T)rhs.m[7],
    m[8] + (T)rhs.m[8],
    m[9] + (T)rhs.m[9],
    m[10] + (T)rhs.m[10],
    m[11] + (T)rhs.m[11],
    m[12] + (T)rhs.m[12],
    m[13] + (T)rhs.m[13],
    m[14] + (T)rhs.m[14],
    m[15] + (T)rhs.m[15]
    );
}

template<typename T>
template<typename T2>
inline tmlMatrix4<T> tmlMatrix4<T>::Sub(const tmlMatrix4<T2> &rhs) const
{
  return tmlMatrix4<T>(
    m[0] - (T)rhs.m[0],
    m[1] - (T)rhs.m[1],
    m[2] - (T)rhs.m[2],
    m[3] - (T)rhs.m[3],
    m[4] - (T)rhs.m[4],
    m[5] - (T)rhs.m[5],
    m[6] - (T)rhs.m[6],
    m[7] - (T)rhs.m[7],
    m[8] - (T)rhs.m[8],
    m[9] - (T)rhs.m[9],
    m[10] - (T)rhs.m[10],
    m[11] - (T)rhs.m[11],
    m[12] - (T)rhs.m[12],
    m[13] - (T)rhs.m[13],
    m[14] - (T)rhs.m[14],
    m[15] - (T)rhs.m[15]
    );
}

template<typename T>
template<typename T2>
inline tmlMatrix4<T>::tmlMatrix4(const tmlMatrix4<T2> &copy)
{
  *this = copy;
}

template<typename T>
template<typename T2>
inline tmlMatrix4<T> tmlMatrix4<T>::Mul(const T2 &rhs) const
{
  return tmlMatrix4<T>(
    m[0] * (T)rhs, m[1] * (T)rhs, m[2] * (T)rhs, m[3] * (T)rhs,
    m[4] * (T)rhs, m[5] * (T)rhs, m[6] * (T)rhs, m[7] * (T)rhs,
    m[8] * (T)rhs, m[9] * (T)rhs, m[10] * (T)rhs, m[11] * (T)rhs,
    m[12] * (T)rhs, m[13] * (T)rhs, m[14] * (T)rhs, m[15] * (T)rhs
    );
}

template<typename T>
inline tmlMatrix4<T> tmlMatrix4<T>::Mul(const T &rhs) const
{
  return tmlMatrix4<T>(
    m[0] * rhs, m[1] * rhs, m[2] * rhs, m[3] * rhs,
    m[4] * rhs, m[5] * rhs, m[6] * rhs, m[7] * rhs,
    m[8] * rhs, m[9] * rhs, m[10] * rhs, m[11] * rhs,
    m[12] * rhs, m[13] * rhs, m[14] * rhs, m[15] * rhs
    );
}

template<typename T>
inline tmlMatrix4<T> tmlMatrix4<T>::Sub(const T &rhs) const
{
  return tmlMatrix4<T>(
    m[0] - rhs, m[1] - rhs, m[2] - rhs, m[3] - rhs,
    m[4] - rhs, m[5] - rhs, m[6] - rhs, m[7] - rhs,
    m[8] - rhs, m[9] - rhs, m[10] - rhs, m[11] - rhs,
    m[12] - rhs, m[13] - rhs, m[14] - rhs, m[15] - rhs
    );
}

template<typename T>
inline tmlMatrix4<T> tmlMatrix4<T>::Add(const T &rhs) const
{
  return tmlMatrix4<T>(
    m[0] + rhs, m[1] + rhs, m[2] + rhs, m[3] + rhs,
    m[4] + rhs, m[5] + rhs, m[6] + rhs, m[7] + rhs,
    m[8] + rhs, m[9] + rhs, m[10] + rhs, m[11] + rhs,
    m[12] + rhs, m[13] + rhs, m[14] + rhs, m[15] + rhs
    );
}

template<typename T>
inline tmlMatrix4<T> tmlMatrix4<T>::AddDiagonal(const T &rhs) const
{
  tmlMatrix4<T> ret = *this;
  ret.m[0] += rhs;
  ret.m[5] += rhs;
  ret.m[10] += rhs;
  ret.m[15] += rhs;
  return ret;
}

template<typename T>
inline const tmlMatrix4<T>& tmlMatrix4<T>::operator=(const tmlMatrix4<T> &copy)
{
  memcpy(&m, &copy.m, sizeof(T) * 16);
  return *this;
}

template<typename T>
inline tmlVector3<T> tmlMatrix4<T>::Mul(const tmlVector3<T> &rhs) const
{
  return ((*this) * tmlVector4<T>(rhs, 1)).xyz();
}

template<typename T>
inline tmlMatrix4<T> tmlMatrix4<T>::Inverse() const
{
  return Cofactors().Transpose().Mul((T)1 / Determinate());
}

template<typename T>
template<typename T2>
inline tmlMatrix4<T> tmlMatrix4<T>::operator*(const tmlMatrix4<T2> &rhs) const
{
  return Mul<T2>(rhs);
}

template<typename T>
inline tmlVector4<T>
inline tmlMatrix4<T>::operator*(const tmlVector4<T> &rhs) const
{
  return Mul(rhs);
}

template<typename T>
inline tmlVector3<T>
inline tmlMatrix4<T>::operator*(const tmlVector3<T> &rhs) const
{ 
  return Mul(rhs);
}

template<typename T>
inline tmlMatrix4<T> tmlMatrix4<T>::operator*(const T &rhs) const
{
  return Mul(rhs);
}

template<typename T>
inline tmlMatrix4<T> tmlMatrix4<T>::operator*(const tmlMatrix4<T> &rhs) const
{
  return Mul(rhs);
}

template<typename T>
inline bool tmlMatrix4<T>::operator==(const tmlMatrix4<T> &rhs) const
{
  return memcmp(&m, &rhs.m, sizeof(T) * 16) == 0;
}

template<typename T>
inline bool tmlMatrix4<T>::operator!=(const tmlMatrix4<T> &rhs) const
{
  return !(*this == rhs);
}

template<typename T>
inline T& tmlMatrix4<T>::operator[](const int64_t index)
{
  return m[index];
}

template<typename T>
inline const T& tmlMatrix4<T>::operator[](const int64_t index) const
{
  return m[index];
}