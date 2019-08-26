#include <cmath>
#include <plog/Log.h>
#include "Parameters.h"

const float coef = 0.1;

const size_t g_parameter_upper_bound = 100;

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
    m_parameters[parameter::HP] = characteristics->get_characteristic(characteristic::physique);
    m_parameters[parameter::carried_weight] =
            characteristics->get_characteristic(characteristic::strength);
    m_parameters[parameter::critical_hit_chance] =
            characteristics->get_characteristic(characteristic::luck) * coef;
    m_parameters[parameter::dodge_chance] = ((characteristics->get_characteristic(characteristic::luck) +
                                              characteristics->get_characteristic(characteristic::sleight) +
                                              m_parameters[parameter::carried_weight]) / 3) * coef;
    set_parameters_upper_bound();
}

void Parameters::avoid_overflow(int &delta, size_t characteristic_value)
{
    if (delta < 0)
    {
        if (characteristic_value < std::abs(delta))
        {
            delta = -characteristic_value;
        }
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
    LOGI << "Characteristic " << static_cast<std::underlying_type<damage_types>::type>(changed_characteristic)
         << " changed on " << delta;


    switch (changed_characteristic)
    {
        case characteristic::physique:
        {
            avoid_overflow(delta, m_parameters[parameter::HP]);
            m_parameters[parameter::HP] += delta;
            break;
        }
        case characteristic::strength:
        {
            avoid_overflow(delta, m_parameters[parameter::carried_weight]);
            m_parameters[parameter::carried_weight] += delta;
            break;
        }
        case characteristic::luck:
        {
            int calculated_diff = delta * coef;
            avoid_overflow(calculated_diff, m_parameters[parameter::critical_hit_chance]);
            m_parameters[parameter::critical_hit_chance] += calculated_diff;
            avoid_overflow(calculated_diff, m_parameters[parameter::dodge_chance]);
            m_parameters[parameter::dodge_chance] += calculated_diff / 3;
            break;
        }
        case characteristic::sleight:
        {
            int calculated_diff = delta * coef;
            avoid_overflow(calculated_diff, m_parameters[parameter::dodge_chance]);
            m_parameters[parameter::dodge_chance] += calculated_diff / 3;
            break;
        }
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
    if (m_damage_reflection[reflection_type] > g_parameter_upper_bound)
    {
        m_damage_reflection[reflection_type] = g_parameter_upper_bound;
    }
}
