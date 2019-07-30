#pragma once

#ifndef DAMNEDWEAPON_H
#define DAMNEDWEAPON_H

#include "weapondecorator.h"

class DamnedWeapon final : public WeaponDecorator
{
    DamnedWeapon(Weapon &decorator, std::uint8_t value, std::string characteristic) ;

    void effect_after_attack(Character &character) override;

private:
    std::string m_characteristic_name;
    std::uint8_t m_value;
    bool m_first_damage;
};

#endif // DAMNEDWEAPON_H
