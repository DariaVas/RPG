#pragma once

#ifndef STUNNINGWEAPON_H
#define STUNNINGWEAPON_H

#include "WeaponDecorator.h"

class StunningWeapon final : public WeaponDecorator
{
public:
    StunningWeapon(std::unique_ptr <Weapon> &weapon);

    void effect_after_attack(Character *character) override;
};

#endif // STUNNINGWEAPON_H
