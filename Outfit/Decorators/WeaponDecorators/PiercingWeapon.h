#pragma once

#ifndef PIERCINGWEAPON_H
#define PIERCINGWEAPON_H

#include "weapondecorator.h"

class PiercingWeapon final : public WeaponDecorator
{
    PiercingWeapon(Weapon &decorator, size_t piercing_power);

    Damage generate_damage(Character &character) override;

private:
    size_t m_piercing_power;
};

#endif // PIERCINGWEAPON_H
