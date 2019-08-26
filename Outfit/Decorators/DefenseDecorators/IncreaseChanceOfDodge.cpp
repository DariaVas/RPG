#include <iostream>
#include "plog/Log.h"
#include "IncreaseChanceOfDodge.h"
#include "Character.h"


IncreaseChanceOfDodge::IncreaseChanceOfDodge(std::unique_ptr <Defense> &decorator, size_t value) :
        DefenseDecorator(decorator),
        m_dodge_power(value)
{
    LOGI << "Created decorator for defense: IncreaseChanceOfDodge, value to increase dodge: " << m_dodge_power;
}

void IncreaseChanceOfDodge::apply_effect(Character *character)
{
    LOGI << "Thing: " << this->get_name()
         << ", applying effect \" increase chance of dodge \", points to increase : " << m_dodge_power
         << std::endl;
    character->increase_parameter(parameter::dodge_chance, m_dodge_power);
    LOGI << "Thing: " << this->get_name() << " effect \" increase chance of dodge \" was applied." << std::endl;

    m_decorator->apply_effect(character);
}

void IncreaseChanceOfDodge::discard_effect(Character *character)
{
    LOGI << "Thing: " << this->get_name()
         << ", discarding effect \" increase chance of dodge \", points to decrease : " << m_dodge_power
         << std::endl;
    character->decrease_parameter(parameter::dodge_chance, m_dodge_power);
    LOGI << "Thing: " << this->get_name() << " effect  \" increase chance of dodge \" was discarded." << std::endl;

    m_decorator->discard_effect(character);
}
