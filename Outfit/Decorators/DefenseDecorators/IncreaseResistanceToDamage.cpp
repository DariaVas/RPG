#include <iostream>
#include <plog/Log.h>
#include "IncreaseResistanceToDamage.h"
#include "Character.h"


IncreaseResistanceToDamage::IncreaseResistanceToDamage(std::unique_ptr <Defense> &decorator, size_t value,
                                                       damage_types damage_type) :
        DefenseDecorator(decorator),
        m_damage_type(damage_type),
        m_resistance_power(value)
{

}

void IncreaseResistanceToDamage::apply_effect(Character *character)
{

    LOGI << "Thing: " << this->get_name() << ", applying effect \"increase resistance to damage\", "
              << "points to increase : " << m_resistance_power
              << " damage damage_types : " << static_cast<std::underlying_type<damage_types>::type>(m_damage_type)
              << std::endl;

    character->increase_resistance(m_damage_type, m_resistance_power);
    LOGI << "Thing: " << this->get_name() << ", applied effect \"increase resistance to damage\"" << std::endl;

    m_decorator->apply_effect(character);
}

void IncreaseResistanceToDamage::discard_effect(Character *character)
{
    LOGI << "Thing: " << this->get_name() << ", discarding effect \"increase resistance to damage\", "
              << "points to decrease : " << m_resistance_power
              << " damage damage_types : " << static_cast<std::underlying_type<damage_types>::type>(m_damage_type)
              << std::endl;
    character->decrease_resistance(m_damage_type, m_resistance_power);
    LOGI << "Thing: " << this->get_name() << ", discarded effect \"increase resistance to damage\"" << std::endl;
    m_decorator->discard_effect(character);
}
