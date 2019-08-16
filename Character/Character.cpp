#include "Character.h"

Character::Character(Outfit &outfit, const CharacterizationObservable &characterization) :
        m_outfit(std::move(outfit)),
        m_characterization(characterization)
{

}

void Character::increase_characteristic(std::string feature_name, size_t feature_value)
{
    size_t ch_value = m_characterization.get_characteristic(feature_name);

    m_characterization.set_characteristic(feature_name, ch_value+feature_value);
}

void Character::decrease_characteristic(std::string feature_name, size_t feature_value)
{
    size_t ch_value = m_characterization.get_characteristic(feature_name);

    if(ch_value < feature_value)
    {
        m_characterization.set_characteristic(feature_name, 0);
    }
    else
    {
        m_characterization.set_characteristic(feature_name, ch_value - feature_value);
    }
}


size_t Character::get_characteristic(std::string feature_name)
{
   return m_characterization.get_characteristic(feature_name);
}

void  Character::increase_parameter(parameter p, size_t value)
{
    m_parameters.set_parameter(p, m_parameters.get_parameter(p) + value);
}

void  Character::decrease_parameter(parameter p, size_t value)
{
    if(m_parameters.get_parameter(p) < value)
    {
        m_parameters.set_parameter(p, 0);
    }
    else
    {
        m_parameters.set_parameter(p, m_parameters.get_parameter(p) - value);
    }
}

void  Character::increase_resistance(types resistance_type, int value)
{
    m_parameters.set_damage_resistance(resistance_type, m_parameters.get_damage_resistance(resistance_type)+ value);
}

void  Character::decrease_resistance(types resistance_type, int value)
{
    if(m_parameters.get_damage_resistance(resistance_type) < value)
    {
        m_parameters.set_damage_resistance(resistance_type, 0);
    }
    else
    {
        m_parameters.set_damage_resistance(resistance_type, m_parameters.get_damage_resistance(resistance_type) - value);
    }
}

void  Character::increase_reflection_of_damage(types damage_type, int value)
{
    m_parameters.set_damage_reflection(damage_type, m_parameters.get_damage_reflection(damage_type)+ value);
}

void  Character::decrease_reflection_of_damage(types damage_type, int value)
{
    if(m_parameters.get_damage_reflection(damage_type) < value)
    {
        m_parameters.set_damage_reflection(damage_type, 0);
    }
    else
    {
        m_parameters.set_damage_reflection(damage_type, m_parameters.get_damage_reflection(damage_type) - value);
    }
}


void Character::set_stun(size_t stun_seconds)
{
    m_stunned = true;
    m_stun_seconds = stun_seconds;
}

void Character::break_outfit(size_t breaking_value)
{

}
