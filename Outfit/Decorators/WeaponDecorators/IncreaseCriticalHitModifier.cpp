#include <plog/Log.h>
#include "IncreaseCriticalHitModifier.h"
#include "Character.h"


IncreaseCriticalHitModifier::IncreaseCriticalHitModifier(std::unique_ptr <Weapon> &weapon, size_t value) :
        WeaponDecorator(weapon),
        m_increase_value(value)
{
    LOGI << "Created decorator for weapon: IncreaseCriticalHitModifier "
         << " points to increase : " << m_increase_value;
}

std::vector<Damage> IncreaseCriticalHitModifier::generate_damage(Character *character)
{
    std::vector<Damage> damage = m_weapon->generate_damage(character);
    damage[0].critical_damage_multiplier += m_increase_value;
    LOGI << "Hero " << character->get_hero_name()
         << " generated a damage, and its critical damage multiplier was increased on "
         << m_increase_value << " due to the effect \"Increase critical hit modifier\"";

    return damage;
}
