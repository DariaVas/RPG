#include <iostream>
#include "WeaponDecorator.h"
#include "Character.h"


WeaponDecorator::WeaponDecorator(std::unique_ptr <Weapon> &decorator) :
        Weapon(decorator->get_name(), decorator->get_hold_type(), decorator->get_damage_type(),
               decorator->get_weapon_power()),
        m_decorator(std::move(decorator))
{

}

 std::vector<Damage> WeaponDecorator::generate_damage(Character *character)
{
    return m_decorator->generate_damage(character);
}

void WeaponDecorator::effect_after_attack(Character *character)
{
    m_decorator->effect_after_attack(character);
}

void WeaponDecorator::apply_effect(Character *character)
{
    m_decorator->apply_effect(character);
}

void WeaponDecorator::discard_effect(Character *character)
{
    m_decorator->discard_effect(character);
}

void WeaponDecorator::reduce_durability(unsigned int value)
{
    m_decorator->reduce_durability(value);
}

WeaponDecorator::~WeaponDecorator()
{

}

size_t WeaponDecorator::get_weapon_power() const
{
    return m_decorator->get_weapon_power();
}

damage_types WeaponDecorator::get_damage_type() const
{
    return m_decorator->get_damage_type();
}

bool WeaponDecorator::is_broken()
{
    return m_decorator->is_broken();
}

size_t WeaponDecorator::get_weight()
{
    return m_decorator->get_weight();
}
