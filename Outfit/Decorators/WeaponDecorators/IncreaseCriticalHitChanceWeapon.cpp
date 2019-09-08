#include <plog/Log.h>
#include "IncreaseCriticalHitChanceWeapon.h"
#include "Character.h"


IncreaseCriticalHitChanceWeapon::IncreaseCriticalHitChanceWeapon(std::unique_ptr <Weapon> &weapon, size_t value) :
        WeaponDecorator(weapon),
        m_increase_value(value)
{
    LOGI << "Created decorator for weapon: IncreaseCriticalHitChanceWeapon, "
         << " points to increase : " << m_increase_value;
}

void IncreaseCriticalHitChanceWeapon::apply_effect(Character *character)
{
    character->increase_parameter(parameter::critical_hit_chance, m_increase_value);
    LOGI << "Thing: " << this->get_name() << ", applied effect \" Increase critical hit chance\" " << std::endl;
    m_weapon->apply_effect(character);
}

void IncreaseCriticalHitChanceWeapon::discard_effect(Character *character)
{
    character->decrease_parameter(parameter::critical_hit_chance, m_increase_value);
    LOGI << "Thing: " << this->get_name() << ", discarded effect \" Increase critical hit chance\" " << std::endl;
    m_weapon->discard_effect(character);
}
