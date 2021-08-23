#include "cull/str.h"
#include <stdio.h>

int main()
{
    str* string = str_create("hello");

    str string2 = tostr("hello");

    printf("%s", string->data);

    str_destroy(string);
}