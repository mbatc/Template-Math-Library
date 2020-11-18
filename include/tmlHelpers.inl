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
inline T tmlNumBitsOn(const T &val)
{
  static uint8_t lookup[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };
  if (val == 0)
    return 0;
  uint8_t addr = uint8_t(val & 0x0F);
  return lookup[addr] + tmlNumBitsOn(val >> 4);
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
