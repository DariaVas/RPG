#ifndef INCREASEINGRITICALHITCHANCEWEAPON_H
#define INCREASEINGRITICALHITCHANCEWEAPON_H

#include "weapondecorator.h"
#include <iostream>
#include "Character/Character.h"
#include "Character/Parameters.h"

class IncreasingCriticalHitChanceWeapon final : public WeaponDecorator
{

public:

    IncreasingCriticalHitChanceWeapon(Weapon &decorator, std::uint8_t value) :
            WeaponDecorator(decorator),
            m_increase_value(value)
    {

    }

    void apply_effect(Character &character) override
    {
        auto value = character.get_parameter(Parameter::critical_hit_chance);
        character.set_parameter(Parameter::critical_hit_chance, value + m_increase_value);
        std::cout << "Applied magic effect" << std::endl;
        std::cout << "Increased chance of critical hit, value to increase : " << m_increase_value <<
                  " characteristic before: " << value
                  << " characteristic after: " << character.get_parameter(Parameter::critical_hit_chance) << std::endl;
        m_decorator.apply_effect(character);
    }

    void discard_effect(Character &character) override
    {
        auto value = character.get_parameter(Parameter::critical_hit_chance);
        character.set_parameter(Parameter::critical_hit_chance, value - m_increase_value);
        std::cout << "Discard magic effect" << std::endl;
        std::cout << "Decreased chance of critical hit, value to decrease : " << m_increase_value <<
                  " characteristic before: " << value
                  << " characteristic after: " << character.get_parameter(Parameter::critical_hit_chance) << std::endl;

        m_decorator.discard_effect(character);
    }


private:
    std::uint8_t m_increase_value;
};

#endif // INCREASEINGRITICALHITCHANCEWEAPON_H
