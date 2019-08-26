#include <iostream>
#include <stdexcept>
#include <plog/Log.h>
#include <type_traits>
#include "MagicWeapon.h"
#include "Character.h"

MagicWeapon::MagicWeapon(const std::string &name, holding_type hold_type, damage_types damage_type, size_t weapon_power)
        :
        Weapon(name, hold_type, damage_type, weapon_power)
{
    if (damage_type == damage_types::physical)
    {
        throw std::runtime_error("Magic weapon cannot have physic damage_types of damage");
    }
}

Damage MagicWeapon::generate_damage(Character *ch)
{
    size_t additional_power = calculate_additional_damage(ch->get_characteristic(characteristic::intelligence));
    size_t power = get_weapon_power() + additional_power;
    size_t modifier_of_critical_hit = calculate_modifier_of_critical_hit(
            ch->get_characteristic(characteristic::intelligence));

    LOGI << "Generated base magic damage, code of damage_types:  "
              << static_cast<std::underlying_type<damage_types>::type>(get_damage_type()) <<
              " weapon power = " <<
              get_weapon_power() << " , additional power from characteristic = " <<
              additional_power << " , total power = " << power << std::endl;

    return Damage{get_damage_type(), power, 0, modifier_of_critical_hit};
}

