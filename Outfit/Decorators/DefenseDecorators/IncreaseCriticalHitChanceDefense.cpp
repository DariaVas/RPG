#include <iostream>
#include <plog/Log.h>
#include "IncreaseCriticalHitChanceDefense.h"
#include "Character.h"


IncreaseCriticalHitChanceDefense::IncreaseCriticalHitChanceDefense(std::unique_ptr <Defense> &defense,
                                                                   size_t value) :
        DefenseDecorator(defense),
        m_increase_value(value)
{
    LOGI << "Created decorator for defense: IncreaseCriticalHitChanceDefense, value to increase critical hit: "
         << m_increase_value;
}

void IncreaseCriticalHitChanceDefense::apply_effect(Character *character)
{
    LOGI << "Thing: " << this->get_name() << ", applying effect \" increase critical hit chance\", "
         << "points to increase : " << m_increase_value << std::endl;
    character->increase_parameter(parameter::critical_hit_chance, m_increase_value);
    LOGI << "Thing: " << this->get_name() << ", applied effect \" increase critical hit chance\"" << std::endl;
    m_defense->apply_effect(character);
}


void IncreaseCriticalHitChanceDefense::discard_effect(Character *character)
{
    LOGI << "Thing: " << this->get_name() << ", discarding effect \" increase critical hit chance\", "
         << "points to decrease : " << m_increase_value << std::endl;
    character->decrease_parameter(parameter::critical_hit_chance, m_increase_value);
    LOGI << "Thing: " << this->get_name() << ", discarded effect \" increase critical hit chance\"" << std::endl;

    m_defense->discard_effect(character);
}
