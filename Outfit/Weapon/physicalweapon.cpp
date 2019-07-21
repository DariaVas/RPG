#include "physicalweapon.h"
#include "iostream"

PhysicalWeapon::PhysicalWeapon(const std::string &name, holding_type hold_type, std::uint8_t weapon_power) :
        Weapon(name, hold_type, types::physical, weapon_power)
{

}

Damage PhysicalWeapon::generate_damage(Character &ch)
{
    std::uint8_t max_characteristic = std::max(ch.get_characteristic(Characteristic::sleight),
                                               ch.get_characteristic(Characteristic::strenght));
    std::uint8_t additional_power = calculate_additional_damage(max_characteristic);
    std::uint8_t power = get_weapon_power() + additional_power;
    std::uint8_t modifier_of_critical_hit = calculate_modifier_of_critical_hit(max_characteristic);

    std::cout << "Generated base physic damage, weapon power = " <<
              get_weapon_power() << " , additional power from characteristic = " <<
              additional_power << " , total power = " << power;

    return Damage{get_damage_type(), power, 0, modifier_of_critical_hit};
}