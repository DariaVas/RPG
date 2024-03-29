#include <iostream>
#include <plog/Log.h>
#include "IncreaseReflectionOfDamage.h"
#include "Character.h"
#include "Character.h"


IncreaseReflectionOfDamage::IncreaseReflectionOfDamage(std::unique_ptr <Defense> &defense, size_t value,
                                                       damage_types damage_type) :
        DefenseDecorator(defense),
        m_damage_type(damage_type),
        m_reflection_power(value)
{
    LOGI << "Created decorator for defense: IncreaseReflectionOfDamage, "
         << " damage type: " << static_cast<int>(damage_type)
         << " reflection power: " << m_reflection_power;
}

void IncreaseReflectionOfDamage::apply_effect(Character *character)
{
    LOGI << "Thing: " << this->get_name() << ", applying effect \" increase reflection of damage\", "
         << "points to increase : " << m_reflection_power
         << "  damage damage_types : " << static_cast<std::underlying_type<damage_types>::type>(m_damage_type)
         << std::endl;

    character->increase_reflection_of_damage(m_damage_type, m_reflection_power);
    LOGI << "Thing: " << this->get_name() << ", applied effect \" increase reflection of damage\"" << std::endl;

    m_defense->apply_effect(character);
}

void IncreaseReflectionOfDamage::discard_effect(Character *character)
{
    LOGI << "Thing: " << this->get_name() << ", discarding effect \" increase reflection of damage\", "
         << "points to decrease : " << m_reflection_power
         << " damage damage_types : " << static_cast<std::underlying_type<damage_types>::type>(m_damage_type)
         << std::endl;
    character->decrease_reflection_of_damage(m_damage_type, -m_reflection_power);
    LOGI << "Thing: " << this->get_name() << ", discarded effect \" increase reflection of damage\"" << std::endl;

    m_defense->discard_effect(character);
}
