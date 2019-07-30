#pragma once
#ifndef BREAKINGWEAPON_H
#define BREAKINGWEAPON_H

#include "weapondecorator.h"

class BreakingWeapon final : public WeaponDecorator
{
    BreakingWeapon(Weapon &decorator, std::uint8_t breaking_value);

    void effect_after_attack(Character &character) override;
private:
    std::uint8_t m_breaking_value;
};

#endif // BREAKINGWEAPON_H
