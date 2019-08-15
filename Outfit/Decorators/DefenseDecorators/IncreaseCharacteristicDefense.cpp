#include <iostream>
#include "IncreaseCharacteristicDefense.h"


IncreaseCharacteristicDefense::IncreaseCharacteristicDefense(std::unique_ptr <Defense> &decorator, size_t value,
                                                             std::string characteristic) :
        DefenseDecorator(decorator),
        m_characteristic_name(characteristic),
        m_value(value)
{

}


void IncreaseCharacteristicDefense::apply_effect(Character &character)
{
    size_t ch_value = character.get_characteristic(m_characteristic_name);
    std::cout << "Thing: " << this->get_name() << ", applying effect \" increase characteristic\", "
              << " points to increase : " << ch_value
              << " characteristic to increase : " << m_characteristic_name << std::endl;

    character.set_characteristic(m_characteristic_name, ch_value + m_value);

    std::cout << "Thing: " << this->get_name() << ", applied effect \" increase characteristic\"" << std::endl;
    m_decorator->apply_effect(character);
}

void IncreaseCharacteristicDefense::discard_effect(Character &character)
{
    size_t ch_value = character.get_characteristic(m_characteristic_name);
    std::cout << "Thing: " << this->get_name() << ", discarding effect \" increase characteristic\", "
              << " points to decrease : " << ch_value
              << " characteristic to discard : " << m_characteristic_name << std::endl;
    character.set_characteristic(m_characteristic_name, ch_value - m_value);
    std::cout << "Thing: " << this->get_name() << ", discarded effect \" increase characteristic\" " << std::endl;

    m_decorator->discard_effect(character);
}
