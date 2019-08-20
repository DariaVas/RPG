#ifndef DAMAGE_H
#define DAMAGE_H

#include <cstdint>

enum class damage_types
{
    physical = 1,
    fire,
    ice,
    electric,
    acid
};

struct Damage
{
    damage_types damage_type;
    std::size_t damage_power;
    std::size_t piercing_power;
    std::size_t critical_damage_multiplier;
};

#endif // DAMAGE_H
