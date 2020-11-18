#ifndef tmlLimits_h__
#define tmlLimits_h__

#include <stdint.h>

template<typename T> T tmlLimitsMax() { return{ 0 }; }
template<> inline double tmlLimitsMax<double>();
template<> inline float tmlLimitsMax<float>();
template<> inline int8_t tmlLimitsMax<int8_t>();
template<> inline int16_t tmlLimitsMax<int16_t>();
template<> inline int32_t tmlLimitsMax<int32_t>();
template<> inline int64_t tmlLimitsMax<int64_t>();
template<> inline uint8_t tmlLimitsMax<uint8_t>();
template<> inline uint16_t tmlLimitsMax<uint16_t>();
template<> inline uint32_t tmlLimitsMax<uint32_t>();
template<> inline uint64_t tmlLimitsMax<uint64_t>();

template<typename T> T tmlLimitsMin() { return{ 0 }; }
template<> inline double tmlLimitsMin<double>();
template<> inline float tmlLimitsMin<float>();
template<> inline int8_t tmlLimitsMin<int8_t>();
template<> inline int16_t tmlLimitsMin<int16_t>();
template<> inline int32_t tmlLimitsMin<int32_t>();
template<> inline int64_t tmlLimitsMin<int64_t>();
template<> inline uint8_t tmlLimitsMin<uint8_t>();
template<> inline uint16_t tmlLimitsMin<uint16_t>();
template<> inline uint32_t tmlLimitsMin<uint32_t>();
template<> inline uint64_t tmlLimitsMin<uint64_t>();

template<typename T> T tmlLimitsSmallest() { return T(0); }
template<> inline double tmlLimitsSmallest<double>();
template<> inline float tmlLimitsSmallest<float>();

#include "tmlLimits.inl"

#endif // tmlLimits_h__
