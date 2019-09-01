#pragma once

#ifndef WEAPONDECORATOR_H
#define WEAPONDECORATOR_H

#include <iostream>
#include <memory>
#include "Weapon.h"
#include <vector>

class WeaponDecorator : public Weapon
{
public:
    WeaponDecorator(std::unique_ptr <Weapon> &decorator);

    virtual std::vector<Damage> generate_damage(Character *character) override;

    virtual void effect_after_attack(Character *character) override;

    virtual ~WeaponDecorator() = 0;

protected:
    std::unique_ptr <Weapon> m_decorator;
};

#endif // WEAPONDECORATOR_H
