#include "DamnedWeapon.h"

DamnedWeapon::DamnedWeapon(std::unique_ptr <Weapon> &decorator, size_t value, std::string characteristic) :
        WeaponDecorator(decorator),
        m_characteristic_name(characteristic),
        m_value(value),
        m_first_damage(true)
{

}

void DamnedWeapon::effect_after_attack(Character &character)
{
    if (m_first_damage)
    {
        size_t value = character.get_characteristic(m_characteristic_name);
        character.set_characteristic(m_characteristic_name, value + m_value);
        m_first_damage = false;
    }
    m_decorator->effect_after_attack(character);
}