#include <iostream>
#include "IncreaseReflectionOfDamage.h"
#include "Character.h"
#include "Character.h"


IncreaseReflectionOfDamage::IncreaseReflectionOfDamage(std::unique_ptr <Defense> &decorator, size_t value,
                                                       types damage_type) :
        DefenseDecorator(decorator),
        m_damage_type(damage_type),
        m_reflection_power(value)
{

}

void IncreaseReflectionOfDamage::apply_effect(Character *character)
{
    std::cout << "Thing: " << this->get_name() << ", applying effect \" increase reflection of damage\", "
              << "points to increase : " << m_reflection_power
              << "  damage type : " << m_damage_type << std::endl;

    character->increase_reflection_of_damage(m_damage_type, m_reflection_power);
    std::cout << "Thing: " << this->get_name() << ", applied effect \" increase reflection of damage\"" << std::endl;

    m_decorator->apply_effect(character);
}

void IncreaseReflectionOfDamage::discard_effect(Character *character)
{
    std::cout << "Thing: " << this->get_name() << ", discarding effect \" increase reflection of damage\", "
              << "points to decrease : " << m_reflection_power
              << " damage type : " << m_damage_type << std::endl;
    character->decrease_reflection_of_damage(m_damage_type, -m_reflection_power);
    std::cout << "Thing: " << this->get_name() << ", discarded effect \" increase reflection of damage\"" << std::endl;

    m_decorator->discard_effect(character);
}
