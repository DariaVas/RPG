#include <iostream>
#include "IncreaseCriticalHitChanceDefense.h"
#include "Character.h"


IncreaseCriticalHitChanceDefense::IncreaseCriticalHitChanceDefense(std::unique_ptr <Defense> &decorator,
                                                                   size_t value) :
        DefenseDecorator(decorator),
        m_increase_value(value)
{

}

void IncreaseCriticalHitChanceDefense::apply_effect(Character *character)
{
    std::cout << "Thing: " << this->get_name() << ", applying effect \" increase critical hit chance\", "
              << "points to increase : " << m_increase_value << std::endl;
    character->increase_parameter(parameter::critical_hit_chance, m_increase_value);
    std::cout << "Thing: " << this->get_name() << ", applied effect \" increase critical hit chance\"" << std::endl;
    m_decorator->apply_effect(character);
}


void IncreaseCriticalHitChanceDefense::discard_effect(Character *character)
{
    std::cout << "Thing: " << this->get_name() << ", discarding effect \" increase critical hit chance\", "
              << "points to decrease : " << m_increase_value << std::endl;
    character->decrease_parameter(parameter::critical_hit_chance, m_increase_value);
    std::cout << "Thing: " << this->get_name() << ", discarded effect \" increase critical hit chance\"" << std::endl;

    m_decorator->discard_effect(character);
}
