#pragma once
#ifndef BREAKINGWEAPON_H
#define BREAKINGWEAPON_H

#include "WeaponDecorator.h"

class BreakingWeapon final : public WeaponDecorator
{
public:
    BreakingWeapon(std::unique_ptr <Weapon> &weapon, size_t breaking_value);

    std::vector<Damage> generate_damage(Character *character) override;

private:
    size_t m_breaking_value;
};

#endif // BREAKINGWEAPON_H
