#include <iostream>
#include "IncreaseChanceOfDodge.h"

IncreaseChanceOfDodge::IncreaseChanceOfDodge(std::unique_ptr <Defense> &decorator, size_t value) :
        DefenseDecorator(decorator),
        m_dodge_power(value)
{

}

void IncreaseChanceOfDodge::apply_effect(Character &character)
{
    std::cout << "Thing: " << this->get_name()
              << ", applying effect \" increase chance of dodge \", points to increase : " << m_dodge_power << std::endl;
    character.set_parameter(Parameter::dodge_chance, m_dodge_power);
    std::cout << "Thing: " << this->get_name() << " effect \" increase chance of dodge \" was applied." << std::endl;

    m_decorator->apply_effect(character);
}

void IncreaseChanceOfDodge::discard_effect(Character &character)
{
    std::cout << "Thing: " << this->get_name()
              << ", discarding effect \" increase chance of dodge \", points to decrease : " << m_dodge_power << std::endl;
    character.set_parameter(Parameter::dodge_chance, m_dodge_power);
    std::cout << "Thing: " << this->get_name() << " effect  \" increase chance of dodge \" was discarded." << std::endl;

    m_decorator->discard_effect(character);
}