#include "include/calculator.h"

#include <stdint.h>
#include <stdio.h>
#include <time.h>

uint64_t add(uint64_t x, uint64_t y)
{
    return x+y;
}

uint64_t subtract(uint64_t x, uint64_t y)
{
    return x-y;
}

uint64_t divide(uint64_t x, uint64_t y)
{
    if(y == 0)
    {
        printf("Are you trying to go past the speed of light ? ");
        return 0;
    }

    return x/y;
}

uint64_t multiply(uint64_t x, uint64_t y)
{
    return x*y;
}

uint64_t mod(uint64_t x, uint64_t y)
{
    if(y == 0)
    {
        printf("Undeterministic scenario detected ! Aborting operation.");
        return 0;
    }
    return x%y;
}
