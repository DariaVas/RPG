#include <iostream>
#include "HeroState.h"
#include "Character.h"

void HeroState::_take_damage(Character *victim, Damage &dmg)
{
    victim->decrease_parameter(parameter::HP, dmg.damage_power);
    victim->break_outfit(dmg.damage_power * 0.5);
    std::cout << victim->get_hero_name() << " got a damage, current hitpoints: "
              << victim->get_parameter(parameter::HP) << std::endl;
}
