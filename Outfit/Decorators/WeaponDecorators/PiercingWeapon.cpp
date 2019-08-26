#include <plog/Log.h>
#include "PiercingWeapon.h"
#include "Character.h"


PiercingWeapon::PiercingWeapon(std::unique_ptr <Weapon> &decorator, size_t piercing_power) :
        WeaponDecorator(decorator),
        m_piercing_power(piercing_power)
{

}

Damage PiercingWeapon::generate_damage(Character *character)
{
    Damage damage = m_decorator->generate_damage(character);
    damage.piercing_power += m_piercing_power;
    LOGI << "Hero " << character->get_hero_name() << " generated a damage, and its piercing power was increased on " << m_piercing_power
         << " due to the effect \"Piercing Weapon\"";
    return damage;
}
