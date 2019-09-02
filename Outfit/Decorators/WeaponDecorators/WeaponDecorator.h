#pragma once

#ifndef WEAPONDECORATOR_H
#define WEAPONDECORATOR_H

#include <iostream>
#include <memory>
#include "Weapon.h"
#include <vector>

class WeaponDecorator : public Weapon
{
public:
    WeaponDecorator(std::unique_ptr <Weapon> &decorator);

    virtual std::vector<Damage> generate_damage(Character *character) override;

    virtual void effect_after_attack(Character *character) override;

    virtual void apply_effect(Character *character) override;

    virtual void discard_effect(Character *character) override;

    virtual size_t get_weapon_power() const override;

    virtual damage_types get_damage_type() const override;


    virtual void reduce_durability(unsigned int value) override;

    virtual bool is_broken() override;

    virtual size_t get_weight() override;

    virtual ~WeaponDecorator() = 0;

protected:
    std::unique_ptr <Weapon> m_decorator;
};

#endif // WEAPONDECORATOR_H
