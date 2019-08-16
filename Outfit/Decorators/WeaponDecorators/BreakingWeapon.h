#pragma once
#ifndef BREAKINGWEAPON_H
#define BREAKINGWEAPON_H

#include "WeaponDecorator.h"

class BreakingWeapon final : public WeaponDecorator
{
public:
    BreakingWeapon(std::unique_ptr <Weapon> &decorator, size_t breaking_value);

    void effect_after_attack(Character *character) override;

private:
    size_t m_breaking_value;
};

#endif // BREAKINGWEAPON_H
