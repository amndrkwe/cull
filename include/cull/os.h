#pragma once

#include <stdlib.h>
#include <os.h>
#include <stdint.h>

#ifndef CULL_FUNC
    #define CULL_FUNC inline static
#endif


// get time of day from system clock
CULL_FUNC
double os_time()
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

// portable random, not safe for cryptography.
CULL_FUNC
uint64_t os_random()
{

}

// seed random number generator
CULL_FUNC
void os_random_seed(uint64_t seed)
{

}

