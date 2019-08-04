#pragma once

#ifndef STUNNINGWEAPON_H
#define STUNNINGWEAPON_H

#include "weapondecorator.h"

class StunningWeapon final : public WeaponDecorator
{
    StunningWeapon(Weapon &decorator, std::uint8_t stun_seconds);


    void effect_after_attack(Character &character) override;

private:
    std::uint8_t m_stun_seconds;
};

#endif // STUNNINGWEAPON_H
