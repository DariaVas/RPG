#include <iostream>
#include <plog/Log.h>
#include "PhysicalWeapon.h"
#include "Character.h"

PhysicalWeapon::PhysicalWeapon(const std::string &name, holding_type hold_type, size_t weapon_power) :
        Weapon(name, hold_type, damage_types::physical, weapon_power)
{
    LOGI << "Added physical weapon : " << name
         << " hold type: " << static_cast<int> (hold_type)
         << " damage type: " << static_cast <int> (damage_types::physical)
         << " weapon power: " << weapon_power;
}

Damage PhysicalWeapon::generate_damage(Character *ch)
{
    size_t max_characteristic = std::max(ch->get_characteristic(characteristic::sleight),
                                         ch->get_characteristic(characteristic::strength));
    size_t additional_power = calculate_additional_damage(max_characteristic);
    size_t power = get_weapon_power() + additional_power;
    size_t modifier_of_critical_hit = calculate_modifier_of_critical_hit(max_characteristic);

    LOGI << "Generated base physic damage, weapon power = " <<
         get_weapon_power() << " , additional power from characteristic = " <<
         additional_power << " , total power = " << power << std::endl;

    return Damage{get_damage_type(), power, 0, modifier_of_critical_hit};
}
