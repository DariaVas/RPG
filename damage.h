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
    std::uint8_t damage_power;
    std::uint8_t piercing_power;
    std::uint8_t critical_damage_multiplier;
};

#endif // DAMAGE_H
