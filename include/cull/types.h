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

// check is float type fits any ieee definition
#if FLT_MANT_DIG == 16 && FLT_MAX_EXP == 16
    typedef float f16;
#elif FLT_MANT_DIG == 24 && FLT_MAX_EXP == 128
    typedef float f32;
#elif DBL_MANT_DIG == 53 && DBL_MAX_EXP == 1024
    typedef float f64;
#endif

// same thing but for doubles
#if DBL_MANT_DIG == 24 && DBL_MAX_EXP == 128
    typedef double f32;
#elif DBL_MANT_DIG == 53 && DBL_MAX_EXP == 1024
    typedef double f64;
#elif LDBL_MANT_DIG == 64 && LDBL_MAX_EXP == 16384
    typedef double f80;
#elif DBL_MANT_DIG == 113 && DBL_MAX_EXP == 16384
    typedef double f128;
#elif DBL_MANT_DIG == 237 && DBL_MAX_EXP == 262144
    typedef double f256;
#endif

// same thing but for long doubles
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
    typedef long double f64;
#elif LDBL_MANT_DIG == 64 && LDBL_MAX_EXP == 16384
    typedef long double f80;
#elif LDBL_MANT_DIG == 113 && LDBL_MAX_EXP == 16384
    typedef long double f128;
#elif LDBL_MANT_DIG == 237 && LDBL_MAX_EXP == 262144
    typedef long double f256;
#endif

#ifdef _GLIBCXX_USE_FLOAT128
    typedef __float128 f128;
#endif