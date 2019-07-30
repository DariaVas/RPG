#include "PiercingWeapon.h"

PiercingWeapon::PiercingWeapon(Weapon &decorator, std::uint8_t piercing_power) :
WeaponDecorator(decorator),
m_piercing_power(piercing_power)
{

}

Damage PiercingWeapon::generate_damage(Character &character)
{
Damage damage = m_decorator.generate_damage(character);
damage.piercing_power += m_piercing_power;
return damage;
}