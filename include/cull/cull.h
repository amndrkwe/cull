// random utilities
#pragma once
#ifndef CULL_FUNC
    #define CULL_FUNC inline static
#endif

#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#ifdef _WIN32
    #include <intrin.h>

    CULL_FUNC
    uint64_t cull_getcycles()
    {
        return __rdtsc();
    }
    

#else
    #include <x86intrin.h>

    // get cycles since machine bootup
    uint64_t cull_getcycles()
    {
        unsigned int lo,hi;
        __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
        return ((uint64_t)hi << 32) | lo;
    }

#endif