#ifndef STUNNINGWEAPON_H
#define STUNNINGWEAPON_H

#include "weapondecorator.h"

class StunningWeapon final : public WeaponDecorator
{
    StunningWeapon(Weapon &decorator, std::uint8_t stun_seconds) :
            WeaponDecorator(decorator),
            m_stun_seconds(stun_seconds)
    {

    }

    void effect_after_attack(Character &character) override
    {
        character.set_stun(m_stun_seconds);
        m_decorator.effect_after_attack(character);
    }

private:
    std::uint8_t m_stun_seconds;
};

#endif // STUNNINGWEAPON_H
