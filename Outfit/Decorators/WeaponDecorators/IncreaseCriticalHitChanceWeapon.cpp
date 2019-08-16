#include "IncreaseCriticalHitChanceWeapon.h"
#include "Character.h"


IncreaseCriticalHitChanceWeapon::IncreaseCriticalHitChanceWeapon(std::unique_ptr <Weapon> &decorator, size_t value) :
        WeaponDecorator(decorator),
        m_increase_value(value)
{

}

void IncreaseCriticalHitChanceWeapon::apply_effect(Character *character)
{
    character->increase_parameter(parameter::critical_hit_chance, m_increase_value);
    m_decorator->apply_effect(character);
}

void IncreaseCriticalHitChanceWeapon::discard_effect(Character *character)
{
    character->decrease_parameter(parameter::critical_hit_chance, m_increase_value);

    m_decorator->discard_effect(character);
}
