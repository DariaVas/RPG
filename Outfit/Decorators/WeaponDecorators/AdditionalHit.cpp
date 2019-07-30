#include "AdditionalHit.h"

AdditionalHit::AdditionalHit(Weapon &decorator, std::uint8_t power) :
        WeaponDecorator(decorator),
        m_damage_power(power)
{

}

Damage AdditionalHit::generate_damage(Character &character)
{
    Damage damage = m_decorator.generate_damage(character);
    damage.damage_power += m_damage_power;
    return damage;
}