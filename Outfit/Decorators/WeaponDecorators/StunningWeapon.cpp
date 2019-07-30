#include "StunningWeapon.h"

StunningWeapon::StunningWeapon(Weapon &decorator, std::uint8_t stun_seconds) :
            WeaponDecorator(decorator),
            m_stun_seconds(stun_seconds)
    {

    }

    void StunningWeapon::effect_after_attack(Character &character) override
    {
        character.set_stun(m_stun_seconds);
        m_decorator.effect_after_attack(character);
    }
