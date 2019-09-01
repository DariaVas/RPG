#pragma once
#ifndef ADDITIONALHIT_H
#define ADDITIONALHIT_H

#include "WeaponDecorator.h"

class AdditionalHit : public WeaponDecorator
{
public:
    AdditionalHit(std::unique_ptr <Weapon> &decorator, damage_types type,size_t power);

    std::vector<Damage> generate_damage(Character *character) override;

private:
    size_t m_damage_power;
    damage_types m_damage_type;
};

#endif // ADDITIONALHIT_H
