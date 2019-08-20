#pragma once

#ifndef INCREASINGCHARACTERISTICWEAPON_H
#define INCREASINGCHARACTERISTICWEAPON_H

#include <iostream>
#include "WeaponDecorator.h"
#include "Character.h"

class IncreaseCharacteristicWeapon final : public WeaponDecorator
{
public:

    IncreaseCharacteristicWeapon(std::unique_ptr <Weapon> &decorator, size_t value, characteristic characteristic);

    void apply_effect(Character *character) override;

    void discard_effect(Character *character) override;

private:
    characteristic m_characteristic;
    size_t m_value;
};

#endif // INCREASINGCHARACTERISTICWEAPON_H
