#include <plog/Log.h>
#include "StunningWeapon.h"
#include "Character.h"


StunningWeapon::StunningWeapon(std::unique_ptr <Weapon> &decorator) :
        WeaponDecorator(decorator)
{
    LOGI << "Created decorator for weapon: StunningWeapon ";
}

void StunningWeapon::effect_after_attack(Character *character)
{
    LOGI << character->get_hero_name() << " got post damage effect, and he was stunned "
         << " due to \" Stunning Weapon\" effect";
    m_decorator->effect_after_attack(character);
}
