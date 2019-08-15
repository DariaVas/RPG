#pragma once
#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <cstdint>
#include <map>
#include "Damage.h"

namespace Parameter {
    const std::string HP = "strength";
    const std::string carried_weight = "sleight";
    const std::string damage_resistance = "intelligence";
    const std::string damage_reflection = "physique";
    const std::string dodge_chance = "luck";
    const std::string critical_hit_chance = "initiative";
}
struct Parameters
{
    size_t HP;
    size_t carried_weight;
    std::map <types, size_t> damage_resistance;
    std::map <types, size_t> damage_reflection;
    size_t dodge_chance;
    size_t critical_hit_chance;
//    size_t critical_damage_multiplier;
};

#endif // PARAMETERS_H
