#pragma once

#ifndef INCREASEINGRITICALHITCHANCEWEAPON_H
#define INCREASEINGRITICALHITCHANCEWEAPON_H

#include "weapondecorator.h"
#include <iostream>
#include "Character/Character.h"
#include "Character/Parameters.h"

class IncreaseCriticalHitChanceWeapon final : public WeaponDecorator
{

public:

    IncreaseCriticalHitChanceWeapon(Weapon &decorator, std::uint8_t value) ;

    void apply_effect(Character &character) override;

    void discard_effect(Character &character) override;

private:
    std::uint8_t m_increase_value;
};

#endif // INCREASEINGRITICALHITCHANCEWEAPON_H
