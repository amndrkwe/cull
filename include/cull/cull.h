// random utilities
#pragma once
#ifndef CULL_FUNC
    #define CULL_FUNC inline static
#endif

#include <stdlib.h>
#include <stdint.h>
#include <time.h>

// conditional free
CULL_FUNC
void cull_free(void* block)
{
    if(block != NULL) free(block);
}

CULL_FUNC
uint64_t cull_clock_start()
{
    
}