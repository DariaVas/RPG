#pragma once

#ifndef WEAPONDECORATOR_H
#define WEAPONDECORATOR_H

#include "weapon.h"
#include <iostream>

class WeaponDecorator : public Weapon
{
public:
    WeaponDecorator(Weapon &decorator);
    virtual Damage generate_damage(Character &character) override;

    virtual void effect_before_attack(Character &character) override;
    virtual void effect_after_attack(Character &character) override;

    virtual ~WeaponDecorator() = 0;

protected:
    Weapon &m_decorator;
};

#endif // WEAPONDECORATOR_H
