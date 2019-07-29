#pragma once

#ifndef INCREASECRITICALHITMODIFIER_H
#define INCREASECRITICALHITMODIFIER_H

#include "weapondecorator.h"
#include "Character/Character.h"

class IncreaseCriticalHitModifier final : public WeaponDecorator
{
public:
    IncreaseCriticalHitModifier(Weapon &decorator, std::uint8_t value) :
            WeaponDecorator(decorator),
            m_increase_value(value)
    {

    }

    Damage generate_damage(Character &character) override
    {
        Damage damage = m_decorator.generate_damage(character);
        damage.critical_damage_multiplier += m_increase_value;
        return damage;
    }

private:
    std::uint8_t m_increase_value;
};


#endif // INCREASECRITICALHITMODIFIER_H
