#include "cull/os.h"
#include <stdio.h>

int main()
{
    os_random_seed(os_cycles());
    printf("%llu", os_cycles());
}