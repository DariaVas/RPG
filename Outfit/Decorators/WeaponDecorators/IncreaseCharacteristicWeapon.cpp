#include "IncreaseCharacteristicWeapon.h"
#include "Character.h"


IncreaseCharacteristicWeapon::IncreaseCharacteristicWeapon(std::unique_ptr <Weapon> &decorator, size_t value,
                                                           std::string characteristic) :
        WeaponDecorator(decorator),
        m_characteristic_name(characteristic),
        m_value(value)
{

}

void IncreaseCharacteristicWeapon::apply_effect(Character *character)
{
    character->increase_characteristic(m_characteristic_name, m_value);

    m_decorator->apply_effect(character);
}

void IncreaseCharacteristicWeapon::discard_effect(Character *character)
{
    character->decrease_characteristic(m_characteristic_name, m_value);

    m_decorator->discard_effect(character);
}
