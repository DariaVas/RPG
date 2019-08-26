#include <plog/Log.h>
#include "AdditionalHit.h"
#include "Character.h"

AdditionalHit::AdditionalHit(std::unique_ptr <Weapon> &decorator, size_t power) :
        WeaponDecorator(decorator),
        m_damage_power(power)
{

}

Damage AdditionalHit::generate_damage(Character *character)
{
    Damage damage = m_decorator->generate_damage(character);
    damage.damage_power += m_damage_power;
    LOGI << "Hero " << character->get_hero_name() << " generated a damage, and its power was increased on " << m_damage_power
         << " due to the effect \"Additional hit\"";
    return damage;
}
