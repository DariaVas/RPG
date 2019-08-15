#pragma once

#ifndef PHYSICALWEAPON_H
#define PHYSICALWEAPON_H

#include "Weapon.h"

class PhysicalWeapon final : public Weapon
{
public:
    PhysicalWeapon(const std::string &name, holding_type hold_type, size_t weapon_power);

    Damage generate_damage(Character &character);
};

#endif // PHYSICALWEAPON_H
