#include <stdio.h>
#include "testman.h"
#include "example.h"

void *multiplier_test()
{
    int a;
    for (a = -10; a <10; a++)
    {
        TESTMAN_INT_ASSERT(multiplier(1, a), a);
        TESTMAN_INT_ASSERT(multiplier(2, a), 2*a);
        TESTMAN_INT_ASSERT(multiplier(0, a), 0);     
        TESTMAN_INT_ASSERT(multiplier(a, 1), a);
        TESTMAN_INT_ASSERT(multiplier(a, 2), 2*a);
    }
}

int main(int argc, char* argv[])
{
    testman_init();
    testman_register(multiplier_test);
    return testman_launch();
}