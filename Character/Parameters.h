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
    Parameters(const std::string& owner_name,CharacterizationObservable *characteristics);

    void handle_event(characteristic changed_characteristic, int delta) override;

    size_t get_parameter(parameter p);

    void increase_parameter(parameter p, size_t value);

    void decrease_parameter(parameter p, size_t value);

    size_t get_damage_resistance(damage_types resistance_type);

    size_t get_damage_reflection(damage_types reflection_type);

    void increase_resistance(damage_types resistance_type, size_t value);

    void decrease_resistance(damage_types resistance_type, size_t value);

    void increase_reflection_of_damage(damage_types damage_type, size_t value);

    void decrease_reflection_of_damage(damage_types damage_type, size_t value);

private:
    void set_parameters_upper_bound();

    void change_parameter_according_to_delta(int delta, parameter p);

private:
    std::map <damage_types, size_t> m_damage_resistance;
    std::map <damage_types, size_t> m_damage_reflection;
    std::map <parameter, size_t> m_parameters;
    const std::string m_owner_name;
};

#endif // PARAMETERS_H
