#pragma once
#ifndef INCREASEREFLECTIONOFDAMAGE_H
#define INCREASEREFLECTIONOFDAMAGE_H

#include "DefenseDecorator.h"

class IncreaseReflectionOfDamage final : public DefenseDecorator
{
public:

    IncreaseReflectionOfDamage(Defense &decorator, std::uint8_t value, types &damage_type) :
            DefenseDecorator(decorator),
            m_damage_type(damage_type),
            m_reflection_power(value)
    {

    }

    void apply_effect(Character &character) override
    {

        character.change_reflection_of_damage(m_damage_type, m_reflection_power);
        m_decorator.apply_effect(character);
    }

    void discard_effect(Character &character) override
    {
        character.change_reflection_of_damage(m_damage_type, -m_reflection_power);
        m_decorator.discard_effect(character);
    }

private:
    types m_damage_type;
    std::uint8_t m_reflection_power;
};

#endif // INCREASEREFLECTIONOFDAMAGE_H
