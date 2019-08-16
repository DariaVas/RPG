#include <iostream>
#include "IncreaseResistanceToDamage.h"
#include "Character.h"


IncreaseResistanceToDamage::IncreaseResistanceToDamage(std::unique_ptr <Defense> &decorator, size_t value,
                                                       types damage_type) :
        DefenseDecorator(decorator),
        m_damage_type(damage_type),
        m_resistance_power(value)
{

}

void IncreaseResistanceToDamage::apply_effect(Character *character)
{

    std::cout << "Thing: " << this->get_name() << ", applying effect \"increase resistance to damage\", "
              << "points to increase : " << m_resistance_power
              << " damage type : " << m_damage_type << std::endl;

    character->increase_resistance(m_damage_type, m_resistance_power);
    std::cout << "Thing: " << this->get_name() << ", applied effect \"increase resistance to damage\"" << std::endl;

    m_decorator->apply_effect(character);
}

void IncreaseResistanceToDamage::discard_effect(Character *character)
{
    std::cout << "Thing: " << this->get_name() << ", discarding effect \"increase resistance to damage\", "
              << "points to decrease : " << m_resistance_power
              << " damage type : " << m_damage_type << std::endl;
    character->decrease_resistance(m_damage_type, m_resistance_power);
    std::cout << "Thing: " << this->get_name() << ", discarded effect \"increase resistance to damage\"" << std::endl;
    m_decorator->discard_effect(character);
}
