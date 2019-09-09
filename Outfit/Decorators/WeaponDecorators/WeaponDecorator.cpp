#include <iostream>
#include "WeaponDecorator.h"
#include "Character.h"


WeaponDecorator::WeaponDecorator(std::unique_ptr <Weapon> &weapon) :
        Weapon(weapon->get_name(), weapon->get_hold_type(), weapon->get_damage_type(),
               weapon->get_weapon_power()),
        m_weapon(std::move(weapon))
{

}

 std::vector<Damage> WeaponDecorator::generate_damage(Character *character)
{
    return m_weapon->generate_damage(character);
}

void WeaponDecorator::effect_after_attack(Character *character)
{
    m_weapon->effect_after_attack(character);
}

void WeaponDecorator::apply_effect(Character *character)
{
    m_weapon->apply_effect(character);
}

void WeaponDecorator::discard_effect(Character *character)
{
    m_weapon->discard_effect(character);
}

void WeaponDecorator::reduce_durability(unsigned int value)
{
    m_weapon->reduce_durability(value);
}

size_t WeaponDecorator::get_weapon_power() const
{
    return m_weapon->get_weapon_power();
}

damage_types WeaponDecorator::get_damage_type() const
{
    return m_weapon->get_damage_type();
}

bool WeaponDecorator::is_broken()
{
    return m_weapon->is_broken();
}

size_t WeaponDecorator::get_weight()
{
    return m_weapon->get_weight();
}
