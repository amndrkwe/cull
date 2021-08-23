#include "cull/str.h"
#include <stdio.h>

int main()
{
    str* string = str_create("hello");
    
    str_destroy(string);
}