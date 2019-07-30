#pragma once

#ifndef PIERCINGWEAPON_H
#define PIERCINGWEAPON_H

#include "weapondecorator.h"

class PiercingWeapon final : public WeaponDecorator
{
    PiercingWeapon(Weapon &decorator, std::uint8_t piercing_power) ;

    Damage generate_damage(Character &character) override;

private:
    std::uint8_t m_piercing_power;
};

#endif // PIERCINGWEAPON_H
