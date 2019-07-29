#pragma once

#ifndef PIERCINGWEAPON_H
#define PIERCINGWEAPON_H

#include "weapondecorator.h"

class PiercingWeapon final : public WeaponDecorator
{
    PiercingWeapon(Weapon &decorator, std::uint8_t piercing_power) :
            WeaponDecorator(decorator),
            m_piercing_power(piercing_power)
    {

    }

    Damage generate_damage(Character &character) override
    {
        Damage damage = m_decorator.generate_damage(character);
        damage.piercing_power += m_piercing_power;
        return damage;
    }

private:
    std::uint8_t m_piercing_power;
};

#endif // PIERCINGWEAPON_H
