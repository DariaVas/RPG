#include <plog/Log.h>
#include "PiercingWeapon.h"
#include "Character.h"


PiercingWeapon::PiercingWeapon(std::unique_ptr <Weapon> &weapon, size_t piercing_power) :
        WeaponDecorator(weapon),
        m_piercing_power(piercing_power)
{
    LOGI << "Created decorator for weapon: PiercingWeapon "
         << " piercing power : " << m_piercing_power;
}

std::vector<Damage> PiercingWeapon::generate_damage(Character *character)
{
    std::vector<Damage> damage = m_weapon->generate_damage(character);
    damage[0].piercing_power += m_piercing_power;
    LOGI << "Hero " << character->get_hero_name() << " generated a damage, and its piercing power was increased on "
         << m_piercing_power
         << " due to the effect \"Piercing Weapon\"";
    return damage;
}
