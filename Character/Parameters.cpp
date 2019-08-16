#include "Parameters.h"

void Parameters::handle_event(const CharacterizationObservable* o)
{
    //recalculate params
}

size_t Parameters::get_parameter(parameter p)
{
    return m_parameters[p];
}

void Parameters::set_parameter(parameter p, size_t value)
{
    m_parameters[p] = value;
}

size_t Parameters::get_damage_resistance(types resistance_type)
{
   return m_damage_resistance[resistance_type];
}

size_t Parameters::get_damage_reflection(types reflection_type)
{
    return m_damage_reflection[reflection_type];
}

void Parameters::set_damage_resistance(types resistance_type, size_t value)
{
    m_damage_resistance[resistance_type] = value;
}

void Parameters::set_damage_reflection(types reflection_type, size_t value)
{
    m_damage_reflection[reflection_type] = value;
}
