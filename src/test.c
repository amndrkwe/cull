#include "cull/str.h"
#include <stdio.h>

int main()
{
    str* string = str_create("0x10");

    printf("%u\n", str_uint(string));

    CULL_DEBUG_STRING(string);

    str_destroy(string);
}