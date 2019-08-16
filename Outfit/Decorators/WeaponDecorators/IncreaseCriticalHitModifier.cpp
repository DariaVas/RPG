#include "IncreaseCriticalHitModifier.h"
#include "Character.h"


IncreaseCriticalHitModifier::IncreaseCriticalHitModifier(std::unique_ptr <Weapon> &decorator, size_t value) :
        WeaponDecorator(decorator),
        m_increase_value(value)
{

}

Damage IncreaseCriticalHitModifier::generate_damage(Character *character)
{
    Damage damage = m_decorator->generate_damage(character);
    damage.critical_damage_multiplier += m_increase_value;
    return damage;
}
