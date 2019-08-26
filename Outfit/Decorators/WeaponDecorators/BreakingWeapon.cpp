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

void BreakingWeapon::effect_after_attack(Character *character)
{
    character->break_outfit(m_breaking_value);
    LOGI << character->get_hero_name() << " got post damage effect, his outfit was damaged on " << m_breaking_value
         << " points "
         << " due to \"Breaking Weapon\" effect";
    m_decorator->effect_after_attack(character);
}
