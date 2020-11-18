#include <utility>

template<typename T> inline T tmlMin(const T &a) { return a; }
template<typename T> inline T tmlMax(const T &a) { return a; }

template<typename T, typename T2, typename... Args> inline T tmlMin(const T &first, const T2 &second, Args ...args)
{
  T argMin = (T)atMin(second, std::forward<Args>(args)...);
  return (argMin < first) ? argMin : first;
}

template<typename T, typename T2, typename... Args> inline T tmlMax(const T &first, const T2 &second, Args ...args)
{
  T argMin = (T)atMax(second, std::forward<Args>(args)...);
  return (argMin > first) ? argMin : first;
}

template<typename T> inline T tmlATan2(const T &y, const T &x)
{
  if (x == y == 0) return 0;
  const double rad = sqrt(x * x + y * y);
  return 2 * tmlATan(x <= 0 ? (rad - x) / y : y / (rad + y));
}

template<typename T> 
inline T tmlSquare(const T &x)
{
  return x * x;
}

template<typename T>
inline T tmlSin(const T &rads)
{
  return (T)sin(rads);
}

template<typename T>
inline T tmlCos(const T &rads)
{
  return (T)cos(rads);
}

template<typename T>
inline T tmlTan(const T &rads)
{
  return (T)tan(rads);
}

template<typename T>
inline T tmlASin(const T &rads)
{
  return (T)asin(rads);
}

template<typename T>
inline T tmlACos(const T &rads)
{
  return (T)acos(rads);
}

template<typename T>
inline T tmlATan(const T &rads)
{
  return (T)atan(rads);
}

template<typename T, typename T2>
inline T tmlLerp(const T &a, const T &b, const T2 &time)
{
  return a + (b - a) * (time);
}

template<typename T, typename T2, typename T3>
inline T tmlClamp(const T &val, const T2 &min, const T3 &max)
{
  return tmlMin(max, tmlMax(min, val));
}

template<typename T>
inline tmlVector2<T> tmlSolveQuadratic(const T &a, const T &b, const T &c)
{
  T val = (T)sqrt(b * b - 4 * a * c);
  T ac_2 = 2 * a * c;
  return tmlVector2<T>((-b - val) / ac_2, (-b + val) / ac_2);
}

template<typename InT, typename OutT>
inline OutT tmlDerivative(const InT &val, const std::function<OutT(InT)> &func, const InT step)
{
  return OutT(func(val + step) - func(val - step)) / (step * 2);
}

template<typename InT, typename OutT>
inline OutT tmlNthDerivative(const InT &val, const std::function<OutT(InT)> &func, const int64_t &n, const InT step)
{
  if (n <= 0)
    return tmlDerivative(val, func, step);
  OutT rhs = tmlNthDerivative(val + step, func, n - 1, step);
  OutT lhs = tmlNthDerivative(val - step, func, n - 1, step);
  return OutT(rhs - lhs) / (step * 2);
}

template<typename T>
inline T tmlSigmoid(const T &val)
{
  return 1 / (1 + exp(-val));
}

template<typename T>
inline T tmlSigmoidApprox(const T &val)
{
  static T sigLookup[] = {
    T(0),
    tmlSigmoid(T(-5)),
    tmlSigmoid(T(-4)),
    tmlSigmoid(T(-3)),
    tmlSigmoid(T(-2)),
    tmlSigmoid(T(-1)),
    tmlSigmoid(T(0)),
    tmlSigmoid(T(1)),
    tmlSigmoid(T(2)),
    tmlSigmoid(T(3)),
    tmlSigmoid(T(4)),
    tmlSigmoid(T(5)),
    T(1)
  };
  static int64_t lookupSize = tmlArraySize(sigLookup);
  static int64_t sigMid = lookupSize / 2;

  T offset = val + sigMid;
  int64_t lower = tmlClamp(int64_t(offset), 0, lookupSize - 1);
  int64_t upper = tmlClamp(int64_t(offset + 1), 0, lookupSize - 1);
  return tmlLerp(sigLookup[lower], sigLookup[upper], (offset - lower));
}

template<typename T>
inline T tmlMod(const T &a, const T &b)
{
  return a % b;
}

template<> inline float tmlMod(const float &a, const float &b)
{
  return fmodf(a, b);
}

template<> inline double tmlMod(const double &a, const double &b)
{
  return fmod(a, b);
}

template<typename T>
inline tmlMatrix4<T> tmlMatrixProjection(const T aspect, const T FOV, const T nearPlane, const T farPlane, const T clipSpaceNearZ, const T clipSpaceFarZ)
{
  const T A = (clipSpaceFarZ * farPlane - clipSpaceNearZ * nearPlane) / (nearPlane - farPlane);
  const T B = (clipSpaceFarZ - clipSpaceNearZ) * farPlane * nearPlane / (nearPlane - farPlane);
  const T yScale = 1.0 / tmlTan(FOV / 2);
  return
    tmlMatrix4<T>(
      yScale / aspect, 0, 0, 0,
      0, yScale, 0, 0,
      0, 0, A, B,
      0, 0, -1, 0
      );
}

template<typename T>
inline tmlMatrix4<T> tmlMatrixOrtho(const T width, const T height, const T nearPlane, const T farPlane)
{
  return tmlMatrixOrtho<T>((T)0, width, (T)0, height, nearPlane, farPlane);
}

template<typename T>
inline tmlMatrix4<T> tmlMatrixOrtho(const T left, const T right, const T top, const T bottom, const T nearPlane, const T farPlane)
{
  return
    tmlMatrix4<T>(
    (T)2 / (right - left), 0, 0, 0,
      0, (T)2 / (top - bottom), 0, 0,
      0, 0, 2 / (farPlane - nearPlane), 0,
      -(right + left) / (right - left), -(top + bottom) / (top - bottom), -(farPlane + nearPlane) / (farPlane - nearPlane), 1
      );
}

template<typename T>
inline tmlMatrix4<T> tmlMatrixRotationX(const T rads)
{
  const T c = tmlCos(rads);
  const T s = tmlSin(rads);
  return
    tmlMatrix4<T>(
      1, 0, 0, 0,
      0, c, -s, 0,
      0, s, c, 0,
      0, 0, 0, 1
      );
}

template<typename T>
inline tmlMatrix4<T> tmlMatrixRotationY(const T rads)
{
  const T c = tmlCos(rads);
  const T s = tmlSin(rads);
  return

    tmlMatrix4<T>(
      c, 0, s, 0,
      0, 1, 0, 0,
      -s, 0, c, 0,
      0, 0, 0, 1
      );
}

template<typename T> 
inline tmlMatrix4<T> tmlMatrixRotationZ(const T rads)
{
  const T c = tmlCos(rads);
  const T s = tmlSin(rads);
  return
    tmlMatrix4<T>(
      c, -s, 0, 0,
      s, c, 0, 0,
      0, 0, 1, 0,
      0, 0, 0, 1
      );
}

template<typename T>
inline tmlMatrix4<T> tmlMatrixRotation(const tmlVector3<T> &axis, T rads)
{
  T c = tmlCos(rads);
  T s = tmlSin(rads);
  return
    tmlMatrix4<T>(
      c + tmlSquare(axis.x) * (1 - c), axis.x * axis.y * (1 - c) - axis.z * s, axis.x * axis.z * (1 - c) + axis.y * s, 0,
      axis.y * axis.x * (1 - c) + axis.z * s, c + tmlSquare(axis.y) * (1 - c), axis.y * axis.z * (1 - c) - axis.x * s, 0,
      axis.z * axis.x * (1 - c) - axis.y * s, axis.z * axis.y * (1 - c) + axis.x * s, c + tmlSquare(axis.z) * (1 - c), 0,
      0, 0, 0, 1
      );
}

template<typename T>
inline tmlMatrix4<T> tmlMatrixRotation(const tmlQuaternion<T> &quat)
{
  const tmlQuaternion<T> &q = quat; // for shorter notation
  const T d = q.Length();
  if (d < tmlLimitsSmallest<T>())
    return tmlMatrix4<T>::Identity();

  T s = T(2) / d;
  T xs = q.x * s, ys = q.y * s, zs = q.z * s;
  T wx = q.w * xs, wy = q.w * ys, wz = q.w * zs;
  T xx = q.x * xs, xy = q.x * ys, xz = q.x * zs;
  T yy = q.y * ys, yz = q.y * zs, zz = q.z * zs;

  return
    tmlMatrix4<T>(
      T(1) - (yy + zz), xy - wz, xz + wy, 0,
      xy + wz, T(1) - (xx + zz), yz - wx, 0,
      xz - wy, yz + wx, T(1) - (xx + yy), 0,
      0, 0, 0, 1);
}

template<typename T>
inline tmlMatrix4<T> tmlMatrixTranslation(const tmlVector3<T> &translation)
{
  return
    tmlMatrix4<T>(
      1, 0, 0, translation.x,
      0, 1, 0, translation.y,
      0, 0, 1, translation.z,
      0, 0, 0, 1
      );
}

template<typename T>
inline tmlMatrix4<T> tmlMatrixScale(const tmlVector3<T> &scale)
{
  return
    tmlMatrix4<T>(
      scale.x, 0, 0, 0,
      0, scale.y, 0, 0,
      0, 0, scale.z, 0,
      0, 0, 0, 1
      );
}

template<typename T>
inline tmlMatrix4<T> tmlMatrixScale(const tmlVector4<T> &scale)
{
  return
    tmlMatrix4<T>(
      scale.x, 0, 0, 0,
      0, scale.y, 0, 0,
      0, 0, scale.z, 0,
      0, 0, 0, scale.w
      );
}

template<typename T>
inline tmlMatrix4<T> tmlMatrixScaleUniform(const T &scale)
{
  return
    tmlMatrix4<T>(
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      0, 0, 0, (T)1 / scale
      );
}

template<typename T>
inline void tmlMatrixDecompose(const tmlMatrix4<T> &mat, tmlVector3<T> *pTranslation, tmlVector3<T> *pRotation, tmlVector3<T> *pScale)
{
  if (pTranslation) *pTranslation = tmlMatrixExtractTranslation(mat);
  if (pRotation) *pRotation = tmlMatrixExtractRotation(mat);
  if (pScale) *pScale = tmlMatrixExtractScale(mat);
}

template<typename T>
inline tmlVector3<T> tmlMatrixExtractRotation(const tmlMatrix4<T> &mat)
{
  return tmlMatrixExtractOrientation(mat).Angle();
}

template<typename T>
inline tmlVector3<T> tmlMatrixExtractOrientation(const tmlMatrix4<T> &mat)
{
  return tmlQuaternion(mat).EulerAngles();
}

template<typename T>
inline tmlVector3<T> tmlMatrixExtractTranslation(const tmlMatrix4<T> &mat)
{
  return tmlVector3<T>(mat[3], mat[7], mat[11]);
}

template<typename T>
inline tmlVector3<T> tmlMatrixExtractScale(const tmlMatrix4<T> &mat)
{
  return tmlVector3<T>(
    tmlVector3<T>(mat[0], mat[4], mat[12]).Mag(),
    tmlVector3<T>(mat[1], mat[5], mat[13]).Mag(),
    tmlVector3<T>(mat[2], mat[6], mat[14]).Mag());
}

template<typename T>
inline T tmlNumBitsOn(const T &val)
{
  static uint8_t lookup[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };
  if (val == 0)
    return 0;
  uint8_t addr = uint8_t(val & 0x0F);
  return lookup[addr] + tmlNumBitsOn(val >> 4);
}

template<typename T>
inline tmlMatrix4<T> tmlMatrixYawPitchRoll(const T yaw, const T pitch, const T roll)
{
  return tmlMatrixRotationY(yaw) * tmlMatrixRotationX(pitch) * tmlMatrixRotationZ(roll);
}

template<typename T>
inline tmlMatrix4<T> tmlMatrixYawPitchRoll(const tmlVector3<T> &ypr)
{
  return tmlMatrixYawPitchRoll(ypr.x, ypr.y, ypr.z);
}

inline float tmlSqrt(const float &val)
{
  return sqrtf(val);
}

inline double tmlSqrt(const double &val)
{
  return sqrtl(val);
}

inline int64_t tmlSqrt(const int64_t &val)
{
  return (int64_t)sqrt((double)val);
}

inline int32_t tmlSqrt(const int32_t &val)
{
  return (int32_t)sqrt((double)val);
}

inline int16_t tmlSqrt(const int16_t &val)
{
  return (int16_t)sqrt((double)val);
}

inline int8_t tmlSqrt(const int8_t &val)
{
  return (int8_t)sqrt((double)val);
}
