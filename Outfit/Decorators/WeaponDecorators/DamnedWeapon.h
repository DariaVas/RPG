#pragma once

#ifndef DAMNEDWEAPON_H
#define DAMNEDWEAPON_H

#include "weapondecorator.h"

class DamnedWeapon final : public WeaponDecorator
{
    DamnedWeapon(Weapon &decorator, std::uint8_t value, std::string characteristic) :
            WeaponDecorator(decorator),
            m_characteristic_name(characteristic),
            m_value(value),
            m_first_damage(true)
    {

    }

    void effect_after_attack(Character &character) override
    {
        if (m_first_damage)
        {
            std::uint8_t value = character.get_characteristic(m_characteristic_name);
            character.set_characteristic(m_characteristic_name, value + m_value);
            m_first_damage = false;
        }
        m_decorator.effect_after_attack(character);
    }

private:
    std::string m_characteristic_name;
    std::uint8_t m_value;
    bool m_first_damage;
};

#endif // DAMNEDWEAPON_H
