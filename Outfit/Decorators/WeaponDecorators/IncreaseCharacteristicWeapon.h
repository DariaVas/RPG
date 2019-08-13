#pragma once

#ifndef INCREASINGCHARACTERISTICWEAPON_H
#define INCREASINGCHARACTERISTICWEAPON_H

#include <iostream>
#include "weapondecorator.h"
#include "Character/Character.h"

class IncreaseCharacteristicWeapon final : public WeaponDecorator
{
public:

    IncreaseCharacteristicWeapon(Weapon &decorator, size_t value, std::string characteristic);

    void apply_effect(Character &character) override;

    void discard_effect(Character &character) override;

private:
    std::string m_characteristic_name;
    size_t m_value;
};

#endif // INCREASINGCHARACTERISTICWEAPON_H
