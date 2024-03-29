#include "Utils.h"

//  Windows
#ifdef _WIN32

#include <intrin.h>
uint64_t utils::rdtsc(){
    return __rdtsc();
}

//  Linux/GCC
#else

uint64_t utils::rdtsc()
{
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t) hi << 32) | lo;
}

#endif

void utils::safely_decrease_unsigned_value(size_t& value, size_t delta)
{
    if (value <= delta)
    {
        value = 0;
    }
    else
    {
        value -=delta;
    }
}
