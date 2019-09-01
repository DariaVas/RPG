#include <plog/Log.h>
#include "AdditionalHit.h"
#include "Character.h"

AdditionalHit::AdditionalHit(std::unique_ptr <Weapon> &decorator, damage_types type, size_t power) :
        WeaponDecorator(decorator),
        m_damage_power(power),
        m_damage_type(type)
{
    LOGI << "Created decorator for weapon: AdditionalHit, "
         << " damage type : " <<  static_cast<size_t> (m_damage_type)
         << " damage power : " << m_damage_power;
}

std::vector<Damage> AdditionalHit::generate_damage(Character *character)
{
    std::vector<Damage> damage = m_decorator->generate_damage(character);
    damage.push_back(Damage{m_damage_type, m_damage_power, 0,0});
    LOGI << "Hero " << character->get_hero_name() << " generated additional damage,"
         << " due to the effect \"Additional hit\"";
    return damage;
}
