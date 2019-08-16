#pragma once
#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <cstdint>
#include <map>
#include "Damage.h"
#include "Observer.h"
#include "CharacterizationObservable.h"

enum class parameter
{
    HP=1,
    carried_weight = 2,
    dodge_chance,
    critical_hit_chance,
};


class Parameters : public Observer
{
public:
    void handle_event(const CharacterizationObservable* o) override;
    size_t get_parameter(parameter p);
    void set_parameter(parameter p, size_t value);
    size_t get_damage_resistance(types resistance_type);
    size_t get_damage_reflection(types reflection_type);
    void set_damage_resistance(types resistance_type, size_t value);
    void set_damage_reflection(types reflection_type, size_t value);
private:
    std::map <parameter, size_t> m_parameters;
    std::map <types, size_t> m_damage_resistance;
    std::map <types, size_t> m_damage_reflection;
};

#endif // PARAMETERS_H
