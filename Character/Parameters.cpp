#include <cmath>
#include <plog/Log.h>
#include "Parameters.h"
#include "Utils.h"

const float g_coef = 0.1;
const float g_dodge_coef = 0.33;
const size_t g_parameter_upper_bound = 100;

Parameters::Parameters(const std::string& owner_name,CharacterizationObservable *characteristics)
        : m_damage_resistance
                  {
                          {damage_types::acid,     0},
                          {damage_types::electric, 0},
                          {damage_types::fire,     0},
                          {damage_types::ice,      0},
                          {damage_types::physical, 0}

                  },
          m_damage_reflection
                  {
                          {damage_types::acid,     0},
                          {damage_types::electric, 0},
                          {damage_types::fire,     0},
                          {damage_types::ice,      0},
                          {damage_types::physical, 0}

                  },
          m_owner_name(owner_name)
{
    m_parameters[parameter::HP] = characteristics->get_characteristic(characteristic::physique);
    m_parameters[parameter::carried_weight] =
            characteristics->get_characteristic(characteristic::strength);
    m_parameters[parameter::critical_hit_chance] =
            characteristics->get_characteristic(characteristic::luck) * g_coef;
    m_parameters[parameter::dodge_chance] = (characteristics->get_characteristic(characteristic::luck) * g_dodge_coef +
                                              characteristics->get_characteristic(characteristic::sleight) * g_dodge_coef +
                                              m_parameters[parameter::carried_weight]* g_dodge_coef) * g_coef;
    set_parameters_upper_bound();
}

void Parameters::change_parameter_according_to_delta(int delta, parameter p)
{
    if (delta < 0)
    {
        decrease_parameter(p,std::abs(delta));
    }
    else
    {
        increase_parameter(p, delta);
    }
}

void Parameters::set_parameters_upper_bound()
{
    if (m_parameters[parameter::critical_hit_chance] > g_parameter_upper_bound)
    {
        m_parameters[parameter::critical_hit_chance] = g_parameter_upper_bound;
    }

    if (m_parameters[parameter::dodge_chance] > g_parameter_upper_bound)
    {
        m_parameters[parameter::dodge_chance] = g_parameter_upper_bound;
    }
}

void Parameters::handle_event(characteristic changed_characteristic, int delta)
{
    if(!delta)
    {
        return;
    }

    LOGI << "Characteristic " << static_cast<std::underlying_type<damage_types>::type>(changed_characteristic)
         << " changed on " << delta;


    switch (changed_characteristic)
    {
        case characteristic::physique:
        {
            change_parameter_according_to_delta(delta,  parameter::HP);
            break;
        }
        case characteristic::strength:
        {
            change_parameter_according_to_delta(delta, parameter::carried_weight);
            // Also, change chace of dodge, because it depends on carried weight
            int dodge_delta = delta * g_dodge_coef* g_coef;
            change_parameter_according_to_delta(dodge_delta,  parameter::dodge_chance);
            break;
        }
        case characteristic::luck:
        {
            int critical_hit_delta = delta * g_coef;
            change_parameter_according_to_delta(critical_hit_delta, parameter::critical_hit_chance);
            int dodge_delta = delta * g_dodge_coef* g_coef;
            change_parameter_according_to_delta(dodge_delta,  parameter::dodge_chance);
            break;
        }
        case characteristic::sleight:
        {
            int dodge_delta = delta * g_dodge_coef* g_coef;
            change_parameter_according_to_delta(dodge_delta, parameter::dodge_chance);
            break;
        }
    default:
        break;
    }
}

size_t Parameters::get_parameter(parameter p)
{
    return m_parameters[p];
}

void Parameters::increase_parameter(parameter p, size_t value)
{
    m_parameters[p] += value;
    set_parameters_upper_bound();
}

void Parameters::decrease_parameter(parameter p, size_t value)
{
    utils::safely_decrease_unsigned_value(m_parameters[p], value);
}


size_t Parameters::get_damage_resistance(damage_types resistance_type)
{
    return m_damage_resistance[resistance_type];
}

size_t Parameters::get_damage_reflection(damage_types reflection_type)
{
    return m_damage_reflection[reflection_type];
}


void Parameters::increase_resistance(damage_types resistance_type, size_t value)
{
    m_damage_resistance[resistance_type] += value;
}

void Parameters::decrease_resistance(damage_types resistance_type, size_t value)
{
    utils::safely_decrease_unsigned_value(m_damage_resistance[resistance_type], value);
}

void Parameters::increase_reflection_of_damage(damage_types damage_type, size_t value)
{
    m_damage_reflection[damage_type] += value;
}

void Parameters::decrease_reflection_of_damage(damage_types damage_type, size_t value)
{
    utils::safely_decrease_unsigned_value(m_damage_reflection[damage_type], value);
}
