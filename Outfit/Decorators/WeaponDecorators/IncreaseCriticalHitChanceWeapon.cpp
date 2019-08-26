#include <plog/Log.h>
#include "IncreaseCriticalHitChanceWeapon.h"
#include "Character.h"


IncreaseCriticalHitChanceWeapon::IncreaseCriticalHitChanceWeapon(std::unique_ptr <Weapon> &decorator, size_t value) :
        WeaponDecorator(decorator),
        m_increase_value(value)
{
    LOGI << "Created decorator for weapon: IncreaseCriticalHitChanceWeapon, "
         << " points to increase : " << m_increase_value;
}

void IncreaseCriticalHitChanceWeapon::apply_effect(Character *character)
{
    character->increase_parameter(parameter::critical_hit_chance, m_increase_value);
    LOGI << "Thing: " << this->get_name() << ", applied effect \" Increase critical hit chance\" " << std::endl;
    m_decorator->apply_effect(character);
}

void IncreaseCriticalHitChanceWeapon::discard_effect(Character *character)
{
    character->decrease_parameter(parameter::critical_hit_chance, m_increase_value);
    LOGI << "Thing: " << this->get_name() << ", discarded effect \" Increase critical hit chance\" " << std::endl;
    m_decorator->discard_effect(character);
}
