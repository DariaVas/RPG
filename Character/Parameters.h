#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <cstdint>
#include <map>
#include "damage.h"

namespace Parameter {
    const std::string HP = "strenght";
    const std::string carried_weight = "sleight";
    const std::string damage_resistance = "intelligence";
    const std::string damage_reflection = "physique";
    const std::string dodge_chance = "luck";
    const std::string critical_hit_chance = "initiative";
}
struct Parameters
{
    std::uint8_t HP;
    std::uint8_t carried_weight;
    std::map <types, std::uint8_t> damage_resistance;
    std::map <types, std::uint8_t> damage_reflection;
    std::uint8_t dodge_chance;
    std::uint8_t critical_hit_chance;
//    std::uint8_t critical_damage_multiplier;
};

#endif // PARAMETERS_H
