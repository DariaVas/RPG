#include "IncreaseCharacteristicWeapon.h"

IncreaseCharacteristicWeapon::IncreaseCharacteristicWeapon(Weapon &decorator, size_t value,
                                                           std::string characteristic) :
        WeaponDecorator(decorator),
        m_characteristic_name(characteristic),
        m_value(value)
{

}

void IncreaseCharacteristicWeapon::apply_effect(Character &character)
{
    size_t ch_value = character.get_characteristic(m_characteristic_name);
    character.set_characteristic(m_characteristic_name, ch_value + m_value);
    std::cout << "Apply magic effect" << std::endl;
    std::cout << "Increased " << m_characteristic_name << " characteristic, value to increase : " << m_value <<
              " characteristic before: " << ch_value
              << " characteristic after: " << character.get_characteristic(m_characteristic_name) << std::endl;
    m_decorator.apply_effect(character);
}

void IncreaseCharacteristicWeapon::discard_effect(Character &character)
{
    size_t ch_value = character.get_characteristic(m_characteristic_name);
    character.set_characteristic(m_characteristic_name, ch_value - m_value);
    std::cout << "Discard magic effect" << std::endl;
    std::cout << "Decreased " << m_characteristic_name << " characteristic, value to decrease : " << m_value <<
              " characteristic before: " << ch_value
              << " characteristic after: " << character.get_characteristic(m_characteristic_name) << std::endl;
    m_decorator.discard_effect(character);
}
