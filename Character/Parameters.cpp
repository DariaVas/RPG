#include <cmath>
#include "Parameters.h"

const size_t coefficient = 10;
const size_t critical_hit_coef = 2;
const float dodge_coef = 0.3;
const size_t max_value = 100;

Parameters::Parameters(CharacterizationObservable *characteristics)
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

          }
{
    m_parameters[parameter::HP] = characteristics->get_characteristic(characteristic::physique) * coefficient;
    m_parameters[parameter::carried_weight] =
            characteristics->get_characteristic(characteristic::strength) * coefficient;
    m_parameters[parameter::critical_hit_chance] = characteristics->get_characteristic(characteristic::luck) / critical_hit_coef;
    m_parameters[parameter::dodge_chance] =  (characteristics->get_characteristic(characteristic::luck) +
                                             characteristics->get_characteristic(characteristic::sleight) +
                                             m_parameters[parameter::carried_weight])*dodge_coef;
}

void Parameters::avoid_overflow(int& delta, size_t characteristic_value)
{
    if (delta < 0)
    {
        if(characteristic_value < std::abs(delta))
        {
            delta = -characteristic_value;
        }
    }
}

void Parameters::set_parameters_upper_bound()
{
    if(m_parameters[parameter::critical_hit_chance]  > 100)
    {
        m_parameters[parameter::critical_hit_chance] = 100;
    }

    if(m_parameters[parameter::dodge_chance]  > 100)
    {
        m_parameters[parameter::dodge_chance] = 100;
    }
}

void Parameters::handle_event(characteristic changed_characteristic, const int delta)
{
    int calculated_diff = 0;
    switch (changed_characteristic) {
    case characteristic::physique:
        calculated_diff = delta*coefficient;
        avoid_overflow(calculated_diff, m_parameters[parameter::HP]);
        m_parameters[parameter::HP] = calculated_diff;
        break;
    case characteristic::strength:
        calculated_diff = delta*coefficient;
        avoid_overflow(calculated_diff, m_parameters[parameter::carried_weight]);
        m_parameters[parameter::carried_weight] = calculated_diff;
        break;
    case characteristic::luck:
        calculated_diff = delta/critical_hit_coef;
        avoid_overflow(calculated_diff, m_parameters[parameter::critical_hit_chance]);
        m_parameters[parameter::critical_hit_chance] = calculated_diff;

        calculated_diff = delta*dodge_coef;
        avoid_overflow(calculated_diff, m_parameters[parameter::dodge_chance]);
        m_parameters[parameter::dodge_chance] = calculated_diff;
        break;
    case characteristic::sleight:
        calculated_diff = delta*dodge_coef;
        avoid_overflow(calculated_diff, m_parameters[parameter::dodge_chance]);
        m_parameters[parameter::dodge_chance] = calculated_diff;
        break;
    default:
        throw std::runtime_error("Unknown characteristic");
        break;
    }
    set_parameters_upper_bound();
}

size_t Parameters::get_parameter(parameter p)
{
    return m_parameters[p];
}

void Parameters::set_parameter(parameter p, size_t value)
{
    m_parameters[p] = value;
    set_parameters_upper_bound();
}

size_t Parameters::get_damage_resistance(damage_types resistance_type)
{
    return m_damage_resistance[resistance_type];
}

size_t Parameters::get_damage_reflection(damage_types reflection_type)
{
    return m_damage_reflection[reflection_type];
}

void Parameters::set_damage_resistance(damage_types resistance_type, size_t value)
{
    m_damage_resistance[resistance_type] = value;
}

void Parameters::set_damage_reflection(damage_types reflection_type, size_t value)
{
    m_damage_reflection[reflection_type] = value;
    if(m_damage_reflection[reflection_type] > max_value)
    {
        m_damage_reflection[reflection_type] = max_value;
    }
}
