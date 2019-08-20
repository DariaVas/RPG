#include "DamnedWeapon.h"
#include "Character.h"


DamnedWeapon::DamnedWeapon(std::unique_ptr <Weapon> &decorator, size_t value, characteristic ch_type) :
        WeaponDecorator(decorator),
        m_characteristic(ch_type),
        m_value(value),
        m_first_damage(true)
{

}

void DamnedWeapon::effect_after_attack(Character *character)
{
    if (m_first_damage)
    {
        character->increase_characteristic(m_characteristic, m_value);
        m_first_damage = false;
    }
    m_decorator->effect_after_attack(character);
}
