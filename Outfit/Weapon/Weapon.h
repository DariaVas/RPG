#pragma once

#ifndef WEAPON_H
#define WEAPON_H

#include <vector>
#include <Damage.h>
#include "Thing.h"

enum holding_type
{
    one_handed = 1,
    two_handed
};

class Weapon : public Thing
{
public:
    Weapon(const std::string &name, holding_type hold_type, damage_types damage_type, size_t weapon_power);

    virtual  std::vector<Damage> generate_damage(Character *character) = 0;

    virtual void effect_after_attack(Character *character);

    virtual void apply_effect(Character *character) override;

    virtual void discard_effect(Character *character) override;

    holding_type get_hold_type() const;

    virtual size_t get_weapon_power() const;

    virtual damage_types get_damage_type() const;

protected:
    size_t calculate_modifier_of_critical_hit(size_t characteristic_value);

    size_t calculate_additional_damage(size_t characteristic_value);

private:
    size_t m_weapon_power;
    holding_type m_hold_type;
    damage_types m_damage_type;
};

#endif // WEAPON_H
