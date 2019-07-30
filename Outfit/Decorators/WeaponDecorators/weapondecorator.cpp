#include "weapondecorator.h"
#include <iostream>

WeaponDecorator::WeaponDecorator(Weapon &decorator) :
        Weapon(decorator),
        m_decorator(decorator)
{

}

Damage WeaponDecorator::generate_damage(Character &character)
{
    return m_decorator.generate_damage(character);
}

void WeaponDecorator::effect_before_attack(Character &character)
{
    return m_decorator.effect_before_attack(character);
}

void WeaponDecorator::effect_after_attack(Character &character)
{
    return m_decorator.effect_after_attack(character);
}
