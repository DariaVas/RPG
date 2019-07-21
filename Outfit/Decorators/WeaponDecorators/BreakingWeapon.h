#ifndef BREAKINGWEAPON_H
#define BREAKINGWEAPON_H

#include "weapondecorator.h"

class BreakingWeapon final : public WeaponDecorator
{
    BreakingWeapon(Weapon &decorator, std::uint8_t breaking_value) :
            WeaponDecorator(decorator),
            m_breaking_value(breaking_value)
    {

    }

    void effect_after_attack(Character &character) override
    {
        character.break_outfit(m_breaking_value);
        m_decorator.effect_after_attack(character);
    }

private:
    std::uint8_t m_breaking_value;
};

#endif // BREAKINGWEAPON_H
