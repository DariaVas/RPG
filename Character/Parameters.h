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
    HP = 1,
    carried_weight = 2,
    dodge_chance,
    critical_hit_chance,
};

extern const size_t g_parameter_upper_bound;

class Parameters : public Observer
{
public:
    Parameters(CharacterizationObservable *characteristics);

    void handle_event(characteristic changed_characteristic, int delta) override;

    size_t get_parameter(parameter p);

    void set_parameter(parameter p, size_t value);

    size_t get_damage_resistance(damage_types resistance_type);

    size_t get_damage_reflection(damage_types reflection_type);

    void set_damage_resistance(damage_types resistance_type, size_t value);

    void set_damage_reflection(damage_types reflection_type, size_t value);

private:
    void set_parameters_upper_bound();

    void avoid_overflow(int &delta, size_t characteristic_value);

private:
    std::map <damage_types, size_t> m_damage_resistance;
    std::map <damage_types, size_t> m_damage_reflection;
    std::map <parameter, size_t> m_parameters;
};

#endif // PARAMETERS_H
