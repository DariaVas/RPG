#pragma once

#ifndef PIERCINGWEAPON_H
#define PIERCINGWEAPON_H

#include "WeaponDecorator.h"

class PiercingWeapon final : public WeaponDecorator
{
public:
    PiercingWeapon(std::unique_ptr <Weapon> &decorator, size_t piercing_power);

    Damage generate_damage(Character *character) override;

private:
    size_t m_piercing_power;
};

#endif // PIERCINGWEAPON_H
