#pragma once
#ifndef INCREASECHANCEOFDOBGE_H
#define INCREASECHANCEOFDOBGE_H

#include "DefenseDecorator.h"

class IncreaseChanceOfDobge final : public DefenseDecorator
{
public:
    IncreaseChanceOfDobge(Defense &decorator, std::uint8_t value) :
            DefenseDecorator(decorator),
            m_dobge_power(value)
    {

    }

    void apply_effect(Character &character) override
    {

        character.set_parameter(Parameter::dodge_chance, m_dobge_power);
        m_decorator.apply_effect(character);
    }

    void discard_effect(Character &character) override
    {
        character.set_parameter(Parameter::dodge_chance, -m_dobge_power);
        m_decorator.discard_effect(character);
    }

private:
    std::uint8_t m_dobge_power;
};

#endif // INCREASECHANCEOFDOBGE_H
