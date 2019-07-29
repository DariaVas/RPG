#pragma once

#ifndef WEAPONDECORATOR_H
#define WEAPONDECORATOR_H

#include "weapon.h"
#include <iostream>

class WeaponDecorator : public Weapon
{
public:
    WeaponDecorator(Weapon &decorator) :
            Weapon(decorator),
            m_decorator(decorator)
    {

    }

    virtual Damage generate_damage(Character &character) override
    {
        return m_decorator.generate_damage(character);
    }

    virtual void effect_before_attack(Character &character) override
    {
        return m_decorator.effect_before_attack(character);
    }

    virtual void effect_after_attack(Character &character) override
    {
        return m_decorator.effect_after_attack(character);
    }

    virtual ~WeaponDecorator() override = default;

protected:
    Weapon &m_decorator;
};

#endif // WEAPONDECORATOR_H
