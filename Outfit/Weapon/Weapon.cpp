#include <cmath>
#include "Weapon.h"
#include "Character.h"

Weapon::Weapon(const std::string &name, holding_type hold_type, types damage_type, size_t weapon_power) :
        Thing(name),
        m_weapon_power(weapon_power),
        m_hold_type(hold_type),
        m_damage_type(damage_type)
{

}

size_t Weapon::get_weapon_power() const
{
    return m_weapon_power;
}

types Weapon::get_damage_type() const
{
    return m_damage_type;
}

void Weapon::effect_before_attack(Character *character)
{

}

void Weapon::effect_after_attack(Character *character)
{

}

size_t Weapon::calculate_modifier_of_critical_hit(size_t characteristic_value)
{
    const double koef = 0.3;
    return static_cast<size_t>(std::floor((characteristic_value * koef) + 0.5));
}

size_t Weapon::calculate_additional_damage(size_t characteristic_value)
{
    const double koef = 0.4;
    return static_cast<size_t>(std::floor((characteristic_value * koef) + 0.5));
}

void Weapon::apply_effect(Character *character)
{

}

void Weapon::discard_effect(Character *character)
{

}

holding_type Weapon::get_hold_type() const
{
    return m_hold_type;
}

Weapon::~Weapon()
{

}
