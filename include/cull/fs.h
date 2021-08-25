// simpler file handling in c
#pragma once

#include <fcntl.h> // file stuff
#include <stdint.h> // uint32_t etc
#include <stdio.h> // fprintf
#include <signal.h> // raise()

#ifndef CULL_FUNC
    #define CULL_FUNC inline static
#endif

#ifndef CULL_FILETYPE 
    #define CULL_FILETYPE file
#endif

#define CULL_UNIMPLEMENTED fprintf(stderr, "%s is not implemented yet!\n", __func__); raise(SIGILL)

enum err_codes
{
    CULL_INVALID_PATH,
    CULL_INVALID_READ,
};

enum read_modes
{
    WRITE, 
    READ, 
    WRITE_READ, 
    APPEND
};

typedef struct 
{
    FILE* data;
    char* filetype;
} cull_file;

CULL_FUNC
cull_file* fs_create()
{
    CULL_UNIMPLEMENTED;
}

CULL_FUNC
void fs_delete(cull_file* file)
{
    CULL_UNIMPLEMENTED;
}

CULL_FUNC
void fs_mkdir(const char* directory)
{
    CULL_UNIMPLEMENTED;
}

typedef file CULL_FILETYPE;