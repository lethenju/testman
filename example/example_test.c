#include <stdio.h>
#include "testman.h"
#include "example.h"

void *multiplier_test()
{
    int a;
    for (a = -1024; a <1024; a++)
    {
        testman_int_assert(multiplier(1, a), a);
        testman_int_assert(multiplier(2, a), 2*a);
        testman_int_assert(multiplier(0, a), 0);     
        testman_int_assert(multiplier(a, 1), a);
        testman_int_assert(multiplier(a, 2), 2*a);
    }
}

int main(int argc, char* argv[])
{
    testman_init();
    testman_register(multiplier_test);
    return testman_launch();
}