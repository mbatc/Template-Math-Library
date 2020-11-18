
template<typename T>
inline tmlQuaternion<T>::tmlQuaternion(const tmlVector3<T> &axis, const T &angle) { Set(axis, angle); }

template<typename T>
inline tmlQuaternion<T>::tmlQuaternion(const T &eulerX, const T &eulerY, const T &eulerZ) { Set(eulerX, eulerY, eulerZ); }

template<typename T>
inline tmlQuaternion<T>::tmlQuaternion()
  : x(0)
  , y(0)
  , z(0)
  , w(1)
{}

template<typename T>
inline tmlQuaternion<T>::tmlQuaternion(const T &x, const T &y, const T &z, const T &w)
  : x(x)
  , y(y)
  , z(z)
  , w(w)
{}

template<typename T>
inline void tmlQuaternion<T>::Set(const T &_x, const T &_y, const T &_z, const T &_w)
{
  x = _x;
  y = _y;
  z = _z;
  w = _w;
}

template<typename T>
inline void tmlQuaternion<T>::Set(const tmlVector3<T> &axis, const T &angle)
{
  T dist = axis.Mag();
  T s = tmlSin(angle * T(0.5)) / dist;
  Set(axis.x * s, axis.y * s, axis.z * s, tmlCos(angle * T(0.5)));
}

template<typename T>
inline void tmlQuaternion<T>::Set(const T &eulerX, const T &eulerY, const T &eulerZ)
{
  double cy = cos(eulerY * 0.5);
  double sy = sin(eulerY * 0.5);
  double cp = cos(eulerX * 0.5);
  double sp = sin(eulerX * 0.5);
  double cr = cos(eulerZ * 0.5);
  double sr = sin(eulerZ * 0.5);

  w = cy * cp * cr + sy * sp * sr;
  x = cy * cp * sr - sy * sp * cr;
  y = sy * cp * sr + cy * sp * cr;
  z = sy * cp * cr - cy * sp * sr;
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::zero()
{
  return tmlQuaternion<T>(0, 0, 0, 0);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::Identity()
{
  return tmlQuaternion<T>(0, 0, 0, 1);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::Normalize(const tmlQuaternion<T> &quat)
{
  return quat / Mag(quat);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::Inverse(const tmlQuaternion<T> &quat)
{
  return tmlQuaternion<T>(-quat.x, -quat.y, -quat.z, quat.w);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::Mul(const tmlQuaternion<T> &lhs, const tmlQuaternion<T> &rhs)
{
  return tmlQuaternion<T>(
    lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
    lhs.w * rhs.y + lhs.y * rhs.w + lhs.z * rhs.x - lhs.x * rhs.z,
    lhs.w * rhs.z + lhs.z * rhs.w + lhs.x * rhs.y - lhs.y * rhs.x,
    lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z
    );
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::Mul(const tmlQuaternion<T> &lhs, const T &rhs)
{
  return tmlQuaternion<T>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::Add(const tmlQuaternion<T> &lhs, const tmlQuaternion<T> &rhs)
{
  return tmlQuaternion<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::Sub(const tmlQuaternion<T> &lhs, const tmlQuaternion<T> &rhs)
{
  return tmlQuaternion<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::Div(const tmlQuaternion<T> &lhs, const T &rhs)
{
  T reciprocal = T(1) / rhs;
  return Mul(lhs, reciprocal);
}

template<typename T>
inline T tmlQuaternion<T>::AngleTo(const tmlQuaternion<T> &from, const tmlQuaternion<T> &to)
{
  T s = tmlSqrt(from.Length() * to.Length());
  if (abs(s) < tmlLimitsSmallest<T>())
    return 0;
  return 2 * tmlACos(Dot(to) / s);
}

template<typename T>
inline T tmlQuaternion<T>::Angle(const tmlQuaternion<T> &quat)
{
  return T(2) * tmlACos(quat.w);
}

template<typename T>
inline T tmlQuaternion<T>::Length(const tmlQuaternion<T> &quat)
{
  return Dot(quat, quat);
}

template<typename T>
inline T tmlQuaternion<T>::Mag(const tmlQuaternion<T> &quat)
{
  return tmlSqrt(Length(quat));
}

template<typename T>
inline T tmlQuaternion<T>::Dot(const tmlQuaternion<T> &lhs, const tmlQuaternion<T> &rhs)
{
  return
    lhs.x * rhs.x +
    lhs.y * rhs.y +
    lhs.z * rhs.z +
    lhs.w * rhs.w;
}

template<typename T>
inline tmlVector3<T> tmlQuaternion<T>::Rotate(const tmlQuaternion<T> &quat, const tmlVector3<T> &vec)
{
  tmlQuaternion<T> q = quat * vec;
  q *= quat.Inverse();
  return tmlVector3<T>(q.x, q.y, q.z);
}

template<typename T>
inline tmlVector3<T> tmlQuaternion<T>::Axis(const tmlQuaternion<T> &quat)
{
  T s_sqr = T(1) - tmlSquare(quat.w);
  T s = T(1) / tmlSqrt(s_sqr);
  if (s < tmlLimitsSmallest<T>())
    return tmlVector3<T>(1, 0, 0);
  return tmlVector3<T>(quat.x * s, quat.y * s, quat.z * s);
}

template<typename T>
inline tmlVector3<T> tmlQuaternion<T>::EulerAngles(const tmlQuaternion<T> &quat)
{
  tmlVector3<T> euler;
  // roll (x-axis rotation)
  double sinr_cosp = +2.0 * (quat.w * quat.x + quat.y * quat.z);
  double cosr_cosp = +1.0 - 2.0 * (quat.x * quat.x + quat.y * quat.y);
  euler.z = tmlATan2(sinr_cosp, cosr_cosp);

  // pitch (y-axis rotation)
  double sinp = +2.0 * (quat.w * quat.y - quat.z * quat.x);
  if (fabs(sinp) >= 1)
    euler.x = copysign(atPi_2, sinp); // use 90 degrees if out of range
  else
    euler.x = tmlASin(sinp);

  // yaw (z-axis rotation)
  double siny_cosp = +2.0 * (quat.w * quat.z + quat.x * quat.y);
  double cosy_cosp = +1.0 - 2.0 * (quat.y * quat.y + quat.z * quat.z);
  euler.y = tmlATan2(siny_cosp, cosy_cosp);
  return euler;
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::Slerp(const tmlQuaternion<T> &to, const T &factor) const
{
  tmlQuaternion<T> result = *this;

  T mag = tmlSqrt(Length() * to.Length());
  if (mag > tmlLimitsSmallest<T>())
  {
    const T product = Dot(to) / mag;
    const T absProduct = abs(product);

    if (absProduct < T(1) - tmlLimitsSmallest<T>())
    {
      const T theta = tmlACos(absProduct);
      const T d = tmlSin(theta);
      if (d > 0)
      {
        T sign = product < 0 ? -1 : 1;
        T s0 = tmlSin((T(1) - factor) * theta) / d;
        T s1 = tmlSin(sign * factor * theta) / d;
        result.Set(
          x * s0 + to.x * s1,
          y * s0 + to.y * s1,
          z * s0 + to.z * s1,
          w * s0 + to.w * s1
        );
      }
    }
  }
  return result;
}

template<typename T>
inline bool tmlQuaternion<T>::operator==(const tmlQuaternion<T> &rhs) const
{
  return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
}

template<typename T> 
inline bool tmlQuaternion<T>::operator!=(const tmlQuaternion<T>& rhs) const
{
  return !(*this == rhs);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::operator-() const
{
  return tmlQuaternion<T>(-x, -y, -z, -w);
}

template<typename T>
inline const tmlQuaternion<T>& tmlQuaternion<T>::operator=(const tmlQuaternion<T> &rhs)
{
  x = rhs.x;
  y = rhs.y;
  z = rhs.z;
  w = rhs.w;
  return *this;
}

template<typename T>
inline tmlQuaternion<T> operator*(const tmlVector3<T> &lhs, const tmlQuaternion<T> &rhs)
{
  return tmlQuaternion<T>(
    +lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
    +lhs.y * rhs.w + lhs.z * rhs.x - lhs.x * rhs.z,
    +lhs.z * rhs.w + lhs.x * rhs.y - lhs.y * rhs.x,
    -lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z);
}

template<typename T>
inline tmlQuaternion<T> operator*(const tmlQuaternion<T> &lhs, const tmlVector3<T> &rhs)
{
  return tmlQuaternion<T>(
    lhs.w * rhs.x + lhs.y * rhs.z - lhs.z * rhs.y,
    lhs.w * rhs.y + lhs.z * rhs.x - lhs.x * rhs.z,
    lhs.w * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x,
    -lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::Normalize() const
{
  return Normalize(*this);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::Inverse() const
{
  return Inverse(*this);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::Mul(const tmlQuaternion<T> &rhs) const
{
  return Mul(*this, rhs);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::Mul(const T &rhs) const
{
  return Mul(*this, rhs);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::Add(const tmlQuaternion<T> &rhs) const
{
  return Add(*this, rhs);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::Sub(const tmlQuaternion<T> &rhs) const
{
  return Sub(*this, rhs);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::Div(const T &rhs) const
{
  return Div(*this, rhs);
}

template<typename T>
inline T tmlQuaternion<T>::AngleTo(const tmlQuaternion<T> &to) const
{
  return AngleTo(*this, to);
}

template<typename T>
inline T tmlQuaternion<T>::Angle() const
{
  return Angle(*this);
}

template<typename T>
inline T tmlQuaternion<T>::Length() const
{
  return Length(*this);
}

template<typename T>
inline T tmlQuaternion<T>::Mag() const
{
  return Mag(*this);
}

template<typename T>
inline T tmlQuaternion<T>::Dot(const tmlQuaternion<T>& rhs) const
{
  return Dot(*this, rhs);
}

template<typename T>
inline tmlVector3<T> tmlQuaternion<T>::EulerAngles() const
{
  return EulerAngles(*this);
}

template<typename T>
inline tmlVector3<T> tmlQuaternion<T>::Axis() const
{
  return Axis(*this);
}

template<typename T>
inline tmlVector3<T> tmlQuaternion<T>::Rotate(const tmlVector3<T> &vec) const
{
  return Rotate(*this, vec);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::operator*(const tmlQuaternion<T> &rhs) const
{
  return Mul(rhs);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::operator-(const tmlQuaternion<T> &rhs) const
{ 
  return Sub(rhs);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::operator+(const tmlQuaternion<T> &rhs) const
{
  return Add(rhs); }

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::operator*(const T &rhs) const
{
  return Mul(rhs);
}

template<typename T>
inline tmlQuaternion<T> tmlQuaternion<T>::operator/(const T &rhs) const
{
  return Div(rhs);
}

template<typename T>
inline const tmlQuaternion<T>& tmlQuaternion<T>::operator*=(const tmlQuaternion<T> &rhs)
{
  return *this = Mul(rhs);
}

template<typename T>
inline const tmlQuaternion<T>& tmlQuaternion<T>::operator*=(const T &rhs)
{
  return *this = Mul(rhs);
}

template<typename T>
inline const T& tmlQuaternion<T>::at(int64_t index) const
{
  return (&x)[index];
}

template<typename T>
inline const T& tmlQuaternion<T>::operator[](int64_t index) const
{
  return at(index);
}

template<typename T>
inline T& tmlQuaternion<T>::at(int64_t index)
{
  return (&x)[index];
}

template<typename T>
inline T& tmlQuaternion<T>::operator[](int64_t index)
{
  return at(index);
}

template<typename T>
inline const T* tmlQuaternion<T>::begin() const
{
  return &x;
}

template<typename T>
inline const T* tmlQuaternion<T>::end() const
{
  return &w + 1;
}

template<typename T>
inline T* tmlQuaternion<T>::begin()
{
  return &x;
}

template<typename T>
inline T* tmlQuaternion<T>::end()
{
  return &w + 1;
}
