#ifndef WEAPON_H
#define WEAPON_H

#include <vector>
#include <damage.h>
#include "thing.h"
#include "Character/Character.h"

enum holding_type
{
    one_handed,
    two_handed
};

class Weapon : public Thing
{
public:
    Weapon(const std::string &name, holding_type hold_type, types damage_type, std::uint8_t weapon_power);

    virtual Damage generate_damage(Character &character) = 0;

    virtual void effect_before_attack(Character &character);

    virtual void effect_after_attack(Character &character);

    virtual ~Weapon() = 0;

protected:
    std::uint8_t get_weapon_power();

    types get_damage_type();

    std::uint8_t calculate_modifier_of_critical_hit(std::uint8_t characteristic_value);

    std::uint8_t calculate_additional_damage(std::uint8_t characteristic_value);

private:
    std::uint8_t m_weapon_power;
    holding_type m_hold_type;
    types m_damage_type;
};

#endif // WEAPON_H
