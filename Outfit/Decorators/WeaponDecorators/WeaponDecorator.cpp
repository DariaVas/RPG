#include <iostream>
#include "WeaponDecorator.h"

WeaponDecorator::WeaponDecorator(std::unique_ptr <Weapon> &decorator) :
        Weapon(decorator->get_name(), decorator->get_hold_type(), decorator->get_damage_type(),
               decorator->get_weapon_power()),
        m_decorator(std::move(decorator))
{

}

Damage WeaponDecorator::generate_damage(Character &character)
{
    return m_decorator->generate_damage(character);
}

void WeaponDecorator::effect_before_attack(Character &character)
{
    return m_decorator->effect_before_attack(character);
}

void WeaponDecorator::effect_after_attack(Character &character)
{
    return m_decorator->effect_after_attack(character);
}

WeaponDecorator::~WeaponDecorator()
{

}
