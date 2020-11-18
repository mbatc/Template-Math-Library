
#include <float.h>

template<> inline double tmlLimitsMax<double>() { return DBL_MAX; }
template<> inline float tmlLimitsMax<float>() { return FLT_MAX; }
template<> inline int8_t tmlLimitsMax<int8_t>() { return UINT8_MAX; }
template<> inline int16_t tmlLimitsMax<int16_t>() { return INT16_MAX; }
template<> inline int32_t tmlLimitsMax<int32_t>() { return INT32_MAX; }
template<> inline int64_t tmlLimitsMax<int64_t>() { return INT64_MAX; }
template<> inline uint8_t tmlLimitsMax<uint8_t>() { return UINT8_MAX; }
template<> inline uint16_t tmlLimitsMax<uint16_t>() { return UINT16_MAX; }
template<> inline uint32_t tmlLimitsMax<uint32_t>() { return UINT32_MAX; }
template<> inline uint64_t tmlLimitsMax<uint64_t>() { return UINT64_MAX; }

template<> inline double tmlLimitsMin<double>() { return -DBL_MAX; }
template<> inline float tmlLimitsMin<float>() { return -FLT_MAX; }
template<> inline int8_t tmlLimitsMin<int8_t>() { return INT8_MIN; }
template<> inline int16_t tmlLimitsMin<int16_t>() { return INT16_MIN; }
template<> inline int32_t tmlLimitsMin<int32_t>() { return INT32_MIN; }
template<> inline int64_t tmlLimitsMin<int64_t>() { return INT64_MIN; }
template<> inline uint8_t tmlLimitsMin<uint8_t>() { return 0; }
template<> inline uint16_t tmlLimitsMin<uint16_t>() { return 0; }
template<> inline uint32_t tmlLimitsMin<uint32_t>() { return 0; }
template<> inline uint64_t tmlLimitsMin<uint64_t>() { return 0; }

template<> inline double tmlLimitsSmallest<double>() { return DBL_EPSILON; }
template<> inline float tmlLimitsSmallest<float>() { return FLT_EPSILON; }
