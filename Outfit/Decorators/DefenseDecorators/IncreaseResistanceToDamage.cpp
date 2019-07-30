#include "IncreaseResistanceToDamage.h"

IncreaseResistanceToDamage::IncreaseResistanceToDamage(std::unique_ptr<Defense> &decorator, std::uint8_t value, types damage_type):
        DefenseDecorator(decorator),
        m_damage_type(damage_type),
        m_resistance_power(value)
{

}

void IncreaseResistanceToDamage::apply_effect(Character &character)
{

    character.change_resistance(m_damage_type, m_resistance_power);
    m_decorator->apply_effect(character);
}

void IncreaseResistanceToDamage::discard_effect(Character &character)
{
    character.change_resistance(m_damage_type, -m_resistance_power);
    m_decorator->discard_effect(character);
}
