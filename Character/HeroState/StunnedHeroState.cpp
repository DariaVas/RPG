#include <iostream>
#include <stdexcept>
#include <plog/Log.h>
#include "Character.h"
#include "StunnedHeroState.h"


StunnedHeroState::StunnedHeroState()
        : m_stun_seconds(0)
{
}

std::vector <Damage> StunnedHeroState::generate_damages(Outfit *outfit, Character *ch)
{
    std::cout << ch->get_hero_name() << " is stunned, so he didn't generate damage" << std::endl;
    return std::vector < Damage > {};
}


bool StunnedHeroState::can_dodge(Character *victim)
{
    std::cout << "Victim is stunned, he cannot protect himself" << std::endl;
    return false;
}

Damage StunnedHeroState::try_to_reflect_damage(Character *victim, Damage &damage)
{
    return Damage{damage.damage_type};
}

void StunnedHeroState::take_reflected_damage(Character *attacker, Damage &reflected_dmg)
{
    throw std::logic_error("Stunned hero cannot take reflected damage, because he doesn't damage anyone");
    // stunned hero cannot damage anyone
}

void StunnedHeroState::try_to_create_critical_hit(Character *atacker, Damage &damage)
{
    throw std::logic_error("Stunned hero cannot create critical hit, because he didn't generate a damage");
}

bool StunnedHeroState::take_remained_damage(Character *victim, Damage &dmg)
{
    _take_damage(victim, dmg);
    std::cout << "Victim is stunned, he took all damage." << std::endl;
    return true;
}

void StunnedHeroState::change_state_if_the_times_came(Character *ch)
{
    if(ch->get_characteristic(characteristic::initiative) < m_stun_seconds)
    {
        ch->set_stun(false);
    }
}

void StunnedHeroState::reduce_time_to_next_move(Character *ch, size_t time)
{
    ch->increase_waiting_time(time);
    m_stun_seconds += time;
    change_state_if_the_times_came(ch);
}

bool StunnedHeroState::all_steps_done(Character* ch)
{
    return false;
}
