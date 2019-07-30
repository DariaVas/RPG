#include "IncreaseReflectionOfDamage.h"


IncreaseReflectionOfDamage::IncreaseReflectionOfDamage(std::unique_ptr<Defense> &decorator, std::uint8_t value, types &damage_type) :
        DefenseDecorator(decorator),
        m_damage_type(damage_type),
        m_reflection_power(value)
{

}

void IncreaseReflectionOfDamage::apply_effect(Character &character)
{

    character.change_reflection_of_damage(m_damage_type, m_reflection_power);
    m_decorator->apply_effect(character);
}

void IncreaseReflectionOfDamage::discard_effect(Character &character)
{
    character.change_reflection_of_damage(m_damage_type, -m_reflection_power);
    m_decorator->discard_effect(character);
}
