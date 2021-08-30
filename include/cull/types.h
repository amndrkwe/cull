#pragma once
#include <stdint.h>
#include <float.h>
#include <limits.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef uint32_t uint;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

#if FLT_MANT_DIG == 24 && FLT_MAX_EXP == 128
    typedef float f32;
#elif FLT_MANT_DIG == 53 && FLT_MAX_EXP == 1024
    typedef float f64;
#endif

#if DBL_MANT_DIG == 53 && DBL_MAX_EXP == 1024
    typedef double f64;
#endif

#if LDBL_MANT_DIG == 64 && LDBL_MAX_EXP == 16384
    typedef long double f80;
#endif