#include <plog/Log.h>
#include "IncreaseCriticalHitModifier.h"
#include "Character.h"


IncreaseCriticalHitModifier::IncreaseCriticalHitModifier(std::unique_ptr <Weapon> &decorator, size_t value) :
        WeaponDecorator(decorator),
        m_increase_value(value)
{

}

Damage IncreaseCriticalHitModifier::generate_damage(Character *character)
{
    Damage damage = m_decorator->generate_damage(character);
    damage.critical_damage_multiplier += m_increase_value;
    LOGI << "Hero " << character->get_hero_name() << " generated a damage, and its critical damage multiplier was increased on "
         << m_increase_value << " due to the effect \"Increase critical hit modifier\"";

    return damage;
}
