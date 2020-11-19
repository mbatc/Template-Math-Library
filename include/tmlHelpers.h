#ifndef tmlHelpers_h__
#define tmlHelpers_h__

#include "tmlLimits.h"

#include <math.h>

#define tmlE 2.71828182845904523536         // e
#define tmlLog2e 1.44269504088896340736     // log2(e)
#define tmlLog10e 0.434294481903251827651   // log10(e)
#define tmlLn2 0.693147180559945309417      // ln(2)
#define tmlLn10  2.30258509299404568402     // ln(10)
#define tmlPi 3.14159265358979323846        // pi
#define tmlPi_2 1.57079632679489661923      // pi/2
#define tmlPi_4 0.785398163397448309616     // pi/4
#define tml1_PI 0.318309886183790671538     // 1/pi
#define tml2_PI 0.636619772367581343076     // 2/pi
#define tmlSqrtPi 1.12837916709551257390    // 2/sqrt(pi)
#define tmlSqrt2 1.41421356237309504880     // sqrt(2)
#define tmlSqrt1_2 0.707106781186547524401  // 1/sqrt(2)
#define tmlDegs2Rads(x) ((double)x * 0.017453292519943295769)
#define tmlRads2Degs(x) ((double)x * 57.29577951308232087679)
#define tmlDegs2Radsf(x) ((float)x * 0.017453292519943295769f)
#define tmlRads2Degsf(x) ((float)x * 57.29577951308232087679f)

#define tmlArraySize(val) (sizeof(val) / sizeof(decltype(val[0])))

template<typename T> inline T tmlMin(const T &a);
template<typename T> inline T tmlMax(const T &a);
template<typename T, typename T2, typename... Args> inline T tmlMin(const T &first, const T2 &second, Args ...args);
template<typename T, typename T2, typename... Args> inline T tmlMax(const T &first, const T2 &second, Args ...args);

template<typename T> inline T tmlSquare(const T &x);
template<typename T> inline T tmlSin(const T &rads);
template<typename T> inline T tmlCos(const T &rads);
template<typename T> inline T tmlTan(const T &rads);
template<typename T> inline T tmlASin(const T &rads);
template<typename T> inline T tmlACos(const T &rads);
template<typename T> inline T tmlATan(const T &rads);
template<typename T> inline T tmlATan2(const T &y, const T &x);

template<typename T, typename T2, typename T3> inline T tmlClamp(const T &val, const T2 &min, const T3 &max);

template<typename T> inline T tmlSigmoid(const T &val);
template<typename InT, typename OutT> inline OutT tmlDerivative(const InT &val, OutT (*func)(InT), const InT step = InT(0.001));
template<typename InT, typename OutT> inline OutT tmlNthDerivative(const InT &val, OutT(*func)(InT), const int64_t &n, const InT step = InT(0.001));

template<typename T> inline T tmlMod(const T &a, const T &b);
template<> inline float tmlMod(const float &a, const float &b);
template<> inline double tmlMod(const double &a, const double &b);

template<typename T, typename T2> inline T tmlLerp(const T &a, const T &b, const T2 &time);

template<typename T> inline T tmlNumBitsOn(const T &val);

inline float tmlSqrt(const float &val);
inline double tmlSqrt(const double &val);
inline int64_t tmlSqrt(const int64_t &val);
inline int32_t tmlSqrt(const int32_t &val);
inline int16_t tmlSqrt(const int16_t &val);
inline int8_t tmlSqrt(const int8_t &val);

#endif // tmlHelpers_h__
