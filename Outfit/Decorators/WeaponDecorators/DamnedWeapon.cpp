#include "DamnedWeapon.h"
#include "Character.h"


DamnedWeapon::DamnedWeapon(std::unique_ptr <Weapon> &decorator, size_t value, std::string characteristic) :
        WeaponDecorator(decorator),
        m_characteristic_name(characteristic),
        m_value(value),
        m_first_damage(true)
{

}

void DamnedWeapon::effect_after_attack(Character *character)
{
    if (m_first_damage)
    {
        character->increase_characteristic(m_characteristic_name, m_value);
        m_first_damage = false;
    }
    m_decorator->effect_after_attack(character);
}
