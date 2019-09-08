#pragma once

#ifndef INCREASEINGRITICALHITCHANCEWEAPON_H
#define INCREASEINGRITICALHITCHANCEWEAPON_H

#include "WeaponDecorator.h"
#include <iostream>
#include "Character.h"
#include "Parameters.h"

class IncreaseCriticalHitChanceWeapon final : public WeaponDecorator
{

public:

    IncreaseCriticalHitChanceWeapon(std::unique_ptr <Weapon> &weapon, size_t value);

    void apply_effect(Character *character) override;

    void discard_effect(Character *character) override;

private:
    size_t m_increase_value;
};

#endif // INCREASEINGRITICALHITCHANCEWEAPON_H
