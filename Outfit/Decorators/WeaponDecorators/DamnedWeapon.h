#pragma once

#ifndef DAMNEDWEAPON_H
#define DAMNEDWEAPON_H

#include "WeaponDecorator.h"
#include "CharacterizationObservable.h"

class DamnedWeapon final : public WeaponDecorator
{
public:
    DamnedWeapon(std::unique_ptr <Weapon> &weapon, size_t value, characteristic ch_type);

    void effect_after_attack(Character *character) override;

private:
    characteristic m_characteristic;
    size_t m_value;
    bool m_first_damage;
};

#endif // DAMNEDWEAPON_H
