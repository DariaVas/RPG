#ifndef INCREASERESISTANCETODAMAGE_H
#define INCREASERESISTANCETODAMAGE_H
#include "DefenseDecorator.h"

class IncreaseResistanceToDamage final : public DefenseDecorator
{
public:

    IncreaseResistanceToDamage(Defense &decorator, std::uint8_t value, types& damage_type) :
            DefenseDecorator(decorator),
            m_damage_type(damage_type),
            m_resistance_power(value)
    {

    }

    void apply_effect(Character &character) override
    {

        character.change_resistance(m_damage_type, m_resistance_power);
        m_decorator.apply_effect(character);
    }

    void discard_effect(Character &character) override
    {
        character.change_resistance(m_damage_type, -m_resistance_power);
        m_decorator.discard_effect(character);
    }

private:
    types m_damage_type;
    std::uint8_t m_resistance_power;
};
#endif // INCREASERESISTANCETODAMAGE_H
