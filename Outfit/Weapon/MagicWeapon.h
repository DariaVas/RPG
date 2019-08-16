#pragma once

#ifndef MAGICWEAPON_H
#define MAGICWEAPON_H

#include "Weapon.h"
#include "Damage.h"

class MagicWeapon final : public Weapon
{
public:
    MagicWeapon(const std::string &name, holding_type hold_type, types damage_type, size_t weapon_power);

    Damage generate_damage(Character *character) override;

    ~MagicWeapon() override = default;
};

#endif // MAGICWEAPON_H
