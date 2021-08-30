#pragma once

#include <stdlib.h>
#include <stdint.h>

#ifndef CULL_FUNC
    #define CULL_FUNC inline static
#endif

static uint64_t _cull_seed = 0;
static uint64_t _cull_seed0 = 0;
static uint64_t _cull_seed1 = 0;

// seed random_get
CULL_FUNC
void random_seed(uint64_t seed)
{
    _cull_seed = seed;
}

// seed random_gets
CULL_FUNC
void random_seeds(uint64_t seed)
{
    _cull_seed0 = seed;
    _cull_seed1 ^= _cull_seed0 << _cull_seed0;
}

// return random unsigned long long (uint64_t)
CULL_FUNC
uint64_t random_get()
{
    _cull_seed ^= _cull_seed << 12;
    _cull_seed ^= _cull_seed >> 25;
    _cull_seed ^= _cull_seed << 27;

    return _cull_seed * UINT64_C(2685821657736338717);
}

// return random unsigned long long (uint64_t) with better distribution but slightly slower
CULL_FUNC
uint64_t random_gets()
{
    _cull_seed0 ^= _cull_seed0 << 12;
    _cull_seed0 ^= _cull_seed0 >> 25;
    _cull_seed0 ^= _cull_seed0 << 27;

    _cull_seed1 ^= _cull_seed0 << 12;
    _cull_seed1 ^= _cull_seed0 >> 23;
    _cull_seed1 ^= _cull_seed0 << 11;

    _cull_seed0 ^= _cull_seed1 << 33;
    _cull_seed0 ^= _cull_seed1 >> 13;
    _cull_seed0 ^= _cull_seed1 << 17;

    return (_cull_seed0 * _cull_seed1) * UINT64_C(2685821657736338717);
}

CULL_FUNC
// return uniform distribution from 0 to 1
double random_getf()
{
    return (random_get() / 18446744073709551616.0);
}