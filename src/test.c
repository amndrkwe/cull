#include "cull/str.h"
#include <stdio.h>

int main()
{
    str_t* string = str_create("hello");
    
    str_destroy(string);
}