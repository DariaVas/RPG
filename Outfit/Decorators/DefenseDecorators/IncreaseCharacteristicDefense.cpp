#include <iostream>
#include "IncreaseCharacteristicDefense.h"
#include "Character.h"


IncreaseCharacteristicDefense::IncreaseCharacteristicDefense(std::unique_ptr <Defense> &decorator, size_t value,
                                                             std::string characteristic) :
        DefenseDecorator(decorator),
        m_characteristic_name(characteristic),
        m_value(value)
{

}


void IncreaseCharacteristicDefense::apply_effect(Character *character)
{
    character->increase_characteristic(m_characteristic_name, m_value);

    std::cout << "Thing: " << this->get_name() << ", applied effect \" increase characteristic\"" << std::endl;
    m_decorator->apply_effect(character);
}

void IncreaseCharacteristicDefense::discard_effect(Character *character)
{
    character->decrease_characteristic(m_characteristic_name, m_value);
    std::cout << "Thing: " << this->get_name() << ", discarded effect \" increase characteristic\" " << std::endl;

    m_decorator->discard_effect(character);
}
