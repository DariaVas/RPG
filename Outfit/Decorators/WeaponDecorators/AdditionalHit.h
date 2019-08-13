#pragma once
#ifndef ADDITIONALHIT_H
#define ADDITIONALHIT_H

#include "weapondecorator.h"

class AdditionalHit : public WeaponDecorator
{
public:
    AdditionalHit(Weapon &decorator, size_t power);

    Damage generate_damage(Character &character) override;

private:
    size_t m_damage_power;
};

#endif // ADDITIONALHIT_H
