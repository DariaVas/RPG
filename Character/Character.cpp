#include "Character.h"
#include "ActiveHeroState.h"
#include "StunnedHeroState.h"

Character::Character(Outfit &outfit, const CharacterizationObservable &characterization, const std::string& hero_name) :
        m_outfit(std::move(outfit)),
        m_characterization(characterization),
        m_parameters(&m_characterization),
        m_hero_name(hero_name),
        m_hero_state(new ActiveHeroState())
{
    m_outfit.apply_magic_effect(this);
}

void Character::increase_characteristic(characteristic feature, size_t feature_value)
{
    size_t ch_value = m_characterization.get_characteristic(feature);

    m_characterization.set_characteristic(feature, ch_value + feature_value);
}

void Character::decrease_characteristic(characteristic feature, size_t feature_value)
{
    size_t ch_value = m_characterization.get_characteristic(feature);

    if (ch_value < feature_value)
    {
        m_characterization.set_characteristic(feature, 0);
    } else
    {
        m_characterization.set_characteristic(feature, ch_value - feature_value);
    }
}


size_t Character::get_characteristic(characteristic feature)
{
    return m_characterization.get_characteristic(feature);
}

void Character::increase_parameter(parameter p, size_t value)
{
    m_parameters.set_parameter(p, m_parameters.get_parameter(p) + value);
}

void Character::decrease_parameter(parameter p, size_t value)
{
    if (m_parameters.get_parameter(p) < value)
    {
        m_parameters.set_parameter(p, 0);
    } else
    {
        m_parameters.set_parameter(p, m_parameters.get_parameter(p) - value);
    }
}

void Character::increase_resistance(damage_types resistance_type, size_t value)
{
    m_parameters.set_damage_resistance(resistance_type, m_parameters.get_damage_resistance(resistance_type) + value);
}

void Character::decrease_resistance(damage_types resistance_type, size_t value)
{
    if (m_parameters.get_damage_resistance(resistance_type) < value)
    {
        m_parameters.set_damage_resistance(resistance_type, 0);
    } else
    {
        m_parameters.set_damage_resistance(resistance_type,
                                           m_parameters.get_damage_resistance(resistance_type) - value);
    }
}

void Character::increase_reflection_of_damage(damage_types damage_type, size_t value)
{
    m_parameters.set_damage_reflection(damage_type, m_parameters.get_damage_reflection(damage_type) + value);
}

void Character::decrease_reflection_of_damage(damage_types damage_type, size_t value)
{
    if (m_parameters.get_damage_reflection(damage_type) < value)
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

std::vector<Damage> Character::get_damages()
{
    return m_outfit.generate_damages(*this);
}

size_t Character::get_parameter(parameter p)
{
    return m_parameters.get_parameter(p);
}

const std::string& Character:: get_hero_name()
{
    return m_hero_name;
}

size_t Character::get_resistance(damage_types resistance_type)
{
    return m_parameters.get_damage_resistance(resistance_type);
}

size_t Character::get_reflection(damage_types reflection_type)
{
    return m_parameters.get_damage_reflection(reflection_type);
}
