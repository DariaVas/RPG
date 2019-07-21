#include "Character.h"

Character::Character()
{

}

void Character::set_characteristic(std::string feature_name, std::uint8_t feature_value)
{
    m_characterization.set_characteristic(feature_name, feature_value);
}

std::uint8_t Character::get_characteristic(std::string feature_name)
{
    return m_characterization.get_characteristic(feature_name);
}

std::uint8_t Character::get_parameter(std::string parameter_name)
{
    return 0;
}

void Character::set_parameter(std::string parameter_name, std::uint8_t parameter_value)
{

}

void Character::change_reflection_of_damage(types damage_type, int reflection_delta)
{

}

void Character::change_resistance(types resistance_type, int resistance_delta)
{

}

void Character::set_stun(std::uint8_t stun_seconds)
{
    m_stunned = true;
    m_stun_seconds = stun_seconds;
}

void Character::break_outfit(std::uint8_t breaking_value)
{

}
