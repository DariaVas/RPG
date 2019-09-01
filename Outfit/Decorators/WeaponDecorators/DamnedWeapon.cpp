#include <plog/Log.h>
#include "DamnedWeapon.h"
#include "Character.h"


DamnedWeapon::DamnedWeapon(std::unique_ptr <Weapon> &decorator, size_t value, characteristic ch_type) :
        WeaponDecorator(decorator),
        m_characteristic(ch_type),
        m_value(value),
        m_first_damage(true)
{
    LOGI << "Created decorator for weapon: Damned Weapon, "
         << " chosen characteristic: " << static_cast<int>(m_characteristic)
         << " points to reduce : " << m_value;
}

void DamnedWeapon::effect_after_attack(Character *character)
{
    if (m_first_damage)
    {
        character->decrease_characteristic(m_characteristic, m_value);
        LOGI << character->get_hero_name() << " got post damage effect, one of his characteristic was decreased on "
             << m_value << " points "
             << " due to \"Damned Weapon\" effect";

        m_first_damage = false;
    }
    m_decorator->effect_after_attack(character);
}
