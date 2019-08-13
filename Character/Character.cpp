#include "Character.h"

Character::Character(const Outfit &outfit, const Characterization &characterization) :
        m_outfit(outfit),
        m_characterization(characterization)
{

}

void Character::set_characteristic(std::string feature_name, size_t feature_value)
{
//    m_characterization.set_characteristic(feature_name, feature_value);
}

size_t Character::get_characteristic(std::string feature_name)
{
//    return m_characterization.get_characteristic(feature_name);
    return 0;
}

size_t Character::get_parameter(std::string parameter_name)
{
    return 0;
}

void Character::set_parameter(std::string parameter_name, int parameter_value)
{

}

void Character::change_reflection_of_damage(types damage_type, int reflection_delta)
{

}

void Character::change_resistance(types resistance_type, int resistance_delta)
{

}

void Character::set_stun(size_t stun_seconds)
{
    m_stunned = true;
    m_stun_seconds = stun_seconds;
}

void Character::break_outfit(size_t breaking_value)
{

}
