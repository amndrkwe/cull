#include "cull/random.h"
#include "cull/cull.h"
#include <stdio.h>

uint64_t c1;
uint64_t c2;

uint64_t r1;
uint64_t r2;
uint64_t r3;

uint64_t t1;
uint64_t t2;
uint64_t t3;

uint64_t rand_highest = 0;
uint64_t rand_lowest = 0xffff;

uint64_t get_highest = 0;
uint64_t get_lowest = 0xffff;

uint64_t gets_highest = 0;
uint64_t gets_lowest = 0xffff;


void profile()
{
    for (uint64_t i = 0; i < 100; i++)
    {
        c1 = cull_getcycles();
        r1 = random_get();
        c2 = cull_getcycles();

        t1 = c2 - c1;

        c1 = cull_getcycles();
        r2 = random_gets();
        c2 = cull_getcycles();

        t2 = c2 - c1;

        c1 = cull_getcycles();
        r3 = rand();
        c2 = cull_getcycles();

        t3 = c2 - c1;

        if (t1 > get_highest) get_highest = t1; 
        if (t2 > gets_highest) gets_highest = t2;
        if (t3 > rand_highest) rand_highest = t3;

        if (t1 < get_lowest) get_lowest = t1;
        if (t2 < gets_lowest) gets_lowest = t2;
        if (t3 < rand_lowest) rand_lowest = t3;
    }

    printf("get: l = %llu, h = %llu, a = %lld\n", get_lowest, get_highest, (get_lowest + get_highest) / 2);
    printf("gets: l = %llu, h = %llu, a = %lld\n", gets_lowest, gets_highest, (gets_lowest + gets_highest) / 2);
    printf("rand: l = %llu, h = %llu, a = %lld\n", rand_lowest, rand_highest, (rand_lowest + rand_highest) / 2);
}

int main()
{
    random_seed(cull_getcycles());
    random_seeds(cull_getcycles());
    srand(cull_getcycles());

    for (int i = 0; i < 100; i++)
        profile();

}