#pragma once

#ifndef MAGICWEAPON_H
#define MAGICWEAPON_H

#include "weapon.h"
#include "damage.h"

class MagicWeapon final : public Weapon
{
public:
    MagicWeapon(const std::string &name, holding_type hold_type, types damage_type, std::uint8_t weapon_power);

    Damage generate_damage(Character &character) override;

    ~MagicWeapon() override = default ;
};

#endif // MAGICWEAPON_H
