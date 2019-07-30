#include "IncreaseCriticalHitChanceDefense.h"

IncreaseCriticalHitChanceDefense::IncreaseCriticalHitChanceDefense(std::unique_ptr<Defense> &decorator, std::uint8_t value) :
        DefenseDecorator(decorator),
        m_increase_value(value)
{

}

void IncreaseCriticalHitChanceDefense::apply_effect(Character &character)
{
    auto value = character.get_parameter(Parameter::critical_hit_chance);
    character.set_parameter(Parameter::critical_hit_chance, value + m_increase_value);
    std::cout << "Applied magic effect" << std::endl;
    std::cout << "Increased chance of critical hit, value to increase : " << m_increase_value <<
              " characteristic before: " << value
              << " characteristic after: " << character.get_parameter(Parameter::critical_hit_chance) << std::endl;
    m_decorator->apply_effect(character);
}


void IncreaseCriticalHitChanceDefense::discard_effect(Character &character)
{
    auto value = character.get_parameter(Parameter::critical_hit_chance);
    character.set_parameter(Parameter::critical_hit_chance, value - m_increase_value);
    std::cout << "Discard magic effect" << std::endl;
    std::cout << "Decreased chance of critical hit, value to decrease : " << m_increase_value <<
              " characteristic before: " << value
              << " characteristic after: " << character.get_parameter(Parameter::critical_hit_chance) << std::endl;

    m_decorator->discard_effect(character);
}
