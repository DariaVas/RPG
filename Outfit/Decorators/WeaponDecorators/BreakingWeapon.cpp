#include <plog/Log.h>
#include "BreakingWeapon.h"
#include "Character.h"


BreakingWeapon::BreakingWeapon(std::unique_ptr <Weapon> &decorator, size_t breaking_value) :
        WeaponDecorator(decorator),
        m_breaking_value(breaking_value)
{
    LOGI << "Created decorator for weapon: BreakingWeapon, "
         << " breaking power: " << m_breaking_value;
}

std::vector<Damage> BreakingWeapon::generate_damage(Character *character)
{
    std::vector<Damage> damage = m_decorator->generate_damage(character);
    damage[0].breaking_power += m_breaking_value;
    LOGI << character->get_hero_name() << " got post damage effect, his outfit was damaged on " << m_breaking_value
         << " points "
         << " due to \"Breaking Weapon\" effect";
    return damage;
}
