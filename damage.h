#ifndef DAMAGE_H
#define DAMAGE_H

#include <cstdint>

enum types
{
    physical = 1,
    fire,
    ice,
    electric,
    acid
};

struct Damage
{
    types type;
    size_t damage_power;
    size_t piercing_power;
    size_t critical_damage_multiplier;
};

#endif // DAMAGE_H
