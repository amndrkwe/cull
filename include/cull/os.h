#pragma once

#include <stdlib.h>
#include <stdint.h>



#ifndef CULL_FUNC
    #define CULL_FUNC inline static
#endif

static uint64_t cull_seed = 0x3141592;

#ifdef _WIN32
    #include <intrin.h>

    // get cycles since machine bootup
    CULL_FUNC
    uint64_t os_cycles()
    {
        return __rdtsc();
    }

#else
    #include <x86intrin.h>

    // get cycles since machine bootup
    uint64_t os_cycles()
    {
        unsigned int lo,hi;
        __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
        return ((uint64_t)hi << 32) | lo;
    }

#endif
// get time of day from system clock, in nanoseconds
CULL_FUNC
long os_time()
{

}

// get machine hostname
CULL_FUNC
char* os_hostname()
{

}

// get current username
CULL_FUNC
char* os_username()
{

}

// get user id
CULL_FUNC
int os_userid()
{

}

// sleep
CULL_FUNC
void os_sleep(uint64_t ms)
{

}

// portable and random, not thread safe or safe in any way at all.
CULL_FUNC
uint64_t os_random()
{
    cull_seed = (3141592 * cull_seed + 2531011 + ~45);
    cull_seed = 22 >> ~cull_seed;

    return (cull_seed>>16)&0x7FFF;
}

// seed random number generator
CULL_FUNC
void os_random_seed(uint64_t seed)
{
    cull_seed = seed;
}

