#include <iostream>
#include <plog/Log.h>
#include "IncreaseCharacteristicDefense.h"
#include "Character.h"


IncreaseCharacteristicDefense::IncreaseCharacteristicDefense(std::unique_ptr <Defense> &defense, size_t value,
                                                             characteristic characteristic) :
        DefenseDecorator(defense),
        m_characteristic(characteristic),
        m_value(value)
{
    LOGI << "Created decorator for defense: IncreaseCharacteristicDefense,"
         << " characteristic to increase: " << static_cast<int>(m_characteristic)
         << " value to increase: " << m_value;

}


void IncreaseCharacteristicDefense::apply_effect(Character *character)
{
    character->increase_characteristic(m_characteristic, m_value);

    LOGI << "Thing: " << this->get_name() << ", applied effect \" increase characteristic\"" << std::endl;
    m_defense->apply_effect(character);
}

void IncreaseCharacteristicDefense::discard_effect(Character *character)
{
    character->decrease_characteristic(m_characteristic, m_value);
    LOGI << "Thing: " << this->get_name() << ", discarded effect \" increase characteristic\" " << std::endl;

    m_defense->discard_effect(character);
}
