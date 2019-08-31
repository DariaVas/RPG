#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdlib>
#include <stdint.h>

namespace utils {
    
    class HeroDied : public std::runtime_error
    {
    public:
        HeroDied(const std::string& hero_name): runtime_error(hero_name) {}
    };
    
    uint64_t rdtsc();
}
#endif // UTILS_H
