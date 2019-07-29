#include <math.h>
#include "weapon.h"

Weapon::Weapon(const std::string &name, holding_type hold_type, types damage_type, std::uint8_t weapon_power) :
Thing(name),
m_weapon_power (weapon_power),
m_hold_type(hold_type),
m_damage_type(damage_type)
{

}

std::uint8_t Weapon::get_weapon_power()
{
    return m_weapon_power;
}

types Weapon::get_damage_type()
{
    return m_damage_type;
}

void Weapon::effect_before_attack(Character &character)
{

}

void Weapon::effect_after_attack(Character &character)
{

}

std::uint8_t Weapon::calculate_modifier_of_critical_hit(std::uint8_t characteristic_value)
{
    const double koef = 0.3;
    return static_cast<uint8_t>(std::floor((characteristic_value * koef) + 0.5));
}

std::uint8_t Weapon::calculate_additional_damage(std::uint8_t characteristic_value)
{
    const double koef = 0.4;
    return static_cast<uint8_t>(std::floor((characteristic_value * koef) + 0.5));
}

void Weapon::apply_effect(Character &character)
{

}

void Weapon::discard_effect(Character &character)
{

}
