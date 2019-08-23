#include <iostream>
#include "Character.h"
#include "StunnedHeroState.h"


StunnedHeroState::StunnedHeroState()
{

}

bool StunnedHeroState::can_dodge(Character* victim) 
{
    return false;
}

Damage StunnedHeroState::try_to_reflect_damage(Character* victim, Damage& damage)
{
    return damage;
}

void StunnedHeroState::take_reflected_damage(Character* attacker, Damage& reflected_dmg)
{
    // stunned hero cannot damage anyone
}

void StunnedHeroState::try_to_resist_damage(Character* victim, Damage& damage)
{
    // stunned hero cannot resist damage
}

void StunnedHeroState::try_to_create_critical_hit(Character* atacker, Damage& damage)
{
    // stunned hero cannot create critical hit
}

bool StunnedHeroState::take_remained_damage(Character* victim, Damage &dmg)
{
    _take_damage(victim, dmg);
}
