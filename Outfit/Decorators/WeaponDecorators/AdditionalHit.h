#pragma once
#ifndef ADDITIONALHIT_H
#define ADDITIONALHIT_H

#include "weapondecorator.h"

class AdditionalHit : public WeaponDecorator
{
public:
    AdditionalHit(Weapon &decorator, std::uint8_t power) :
            WeaponDecorator(decorator),
            m_damage_power(power)
    {

    }

    Damage generate_damage(Character &character) override
    {
        Damage damage = m_decorator.generate_damage(character);
        damage.damage_power += m_damage_power;
        return damage;
    }

private:
    std::uint8_t m_damage_power;
};

#endif // ADDITIONALHIT_H
