#include "IncreaseChanceOfDobge.h"

IncreaseChanceOfDobge::IncreaseChanceOfDobge(std::unique_ptr<Defense> &decorator, std::uint8_t value) :
        DefenseDecorator(decorator),
        m_dobge_power(value)
{

}

void IncreaseChanceOfDobge::apply_effect(Character &character)
{

    character.set_parameter(Parameter::dodge_chance, m_dobge_power);
    m_decorator->apply_effect(character);
}

void IncreaseChanceOfDobge::discard_effect(Character &character)
{
    character.set_parameter(Parameter::dodge_chance, -m_dobge_power);
    m_decorator->discard_effect(character);
}
