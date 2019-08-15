#pragma once

#ifndef DAMNEDWEAPON_H
#define DAMNEDWEAPON_H

#include "WeaponDecorator.h"

class DamnedWeapon final : public WeaponDecorator
{
public:
    DamnedWeapon(std::unique_ptr <Weapon> &decorator, size_t value, std::string characteristic);

    void effect_after_attack(Character &character) override;

private:
    std::string m_characteristic_name;
    size_t m_value;
    bool m_first_damage;
};

#endif // DAMNEDWEAPON_H
