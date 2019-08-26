#include <iostream>
#include <stdexcept>
#include <plog/Log.h>
#include "Character.h"
#include "StunnedHeroState.h"


StunnedHeroState::StunnedHeroState(size_t seconds)
    :m_stun_seconds(seconds)
{
    // We set stun seconds to know, when the hero must change state from Stunned  to Active
    // Note! Because of the fight of two heroes goes about 2 second,  it will be stupid if the hero is stunned during the all game.
    //       That is why we will calculate hero steps instead of seconds.
}

std::vector<Damage> StunnedHeroState::generate_damages(Outfit *outfit, Character *ch)
{
    ++m_done_steps;
    std::cout << ch->get_hero_name() << " is stunned, so he didn't generate damage" << std::endl;
    change_state_if_the_times_came(ch);
    return std::vector<Damage> {};
}


bool StunnedHeroState::can_dodge(Character *victim)
{
    ++m_done_steps;
    change_state_if_the_times_came(victim);
    return false;
}

Damage StunnedHeroState::try_to_reflect_damage(Character *victim, Damage &damage)
{
    ++m_done_steps;
    change_state_if_the_times_came(victim);
    return damage;
}

void StunnedHeroState::take_reflected_damage(Character *attacker, Damage &reflected_dmg)
{
    throw std::logic_error("Stunned hero cannot take reflected damage, because he doesn't damage anyone");
    // stunned hero cannot damage anyone
}

void StunnedHeroState::try_to_create_critical_hit(Character *atacker, Damage &damage)
{
    ++m_done_steps;
    change_state_if_the_times_came(atacker);
    // stunned hero cannot create critical hit
}

bool StunnedHeroState::take_remained_damage(Character *victim, Damage &dmg)
{
    _take_damage(victim, dmg);
    ++m_done_steps;
    change_state_if_the_times_came(victim);
    return true;
}

void StunnedHeroState::change_state_if_the_times_came(Character *ch)
{
    ch->set_stun(false);
}
