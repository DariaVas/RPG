#include "BreakingWeapon.h"

BreakingWeapon::BreakingWeapon(Weapon &decorator, std::uint8_t breaking_value) :
WeaponDecorator(decorator),
m_breaking_value(breaking_value)
{

}

void BreakingWeapon::effect_after_attack(Character &character)
{
character.break_outfit(m_breaking_value);
m_decorator.effect_after_attack(character);
}
