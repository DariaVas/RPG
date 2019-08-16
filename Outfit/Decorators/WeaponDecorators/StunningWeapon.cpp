#include "StunningWeapon.h"
#include "Character.h"


StunningWeapon::StunningWeapon(std::unique_ptr <Weapon> &decorator, size_t stun_seconds) :
        WeaponDecorator(decorator),
        m_stun_seconds(stun_seconds)
{

}

void StunningWeapon::effect_after_attack(Character *character)
{
    character->set_stun(m_stun_seconds);
    m_decorator->effect_after_attack(character);
}
