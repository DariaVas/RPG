#include <iostream>
#include <plog/Log.h>
#include "ActiveHeroState.h"
#include "Character.h"
#include "Utils.h"

ActiveHeroState::ActiveHeroState()
{

}

std::vector <Damage> ActiveHeroState::generate_damages(Outfit *outfit, Character *ch)
{
    return outfit->generate_damages(ch);
}


bool ActiveHeroState::can_dodge(Character *victim)
{
    size_t generated_dodge_chance = utils::rdtsc() % 100 + 1;
    size_t hero_dodge_chance = victim->get_parameter(parameter::dodge_chance);
    std::cout << victim->get_hero_name() << " dodge chance: " << hero_dodge_chance
              << " generated dodge chance : " << generated_dodge_chance << std::endl;
    if (generated_dodge_chance < hero_dodge_chance)
    {
        LOGI << victim->get_hero_name() << " dodged damage";
        return true;
    }
    LOGI << victim->get_hero_name() << " didn't dodge damage";
    return false;
}

Damage ActiveHeroState::try_to_reflect_damage(Character *victim, Damage &damage)
{
    size_t reflection = victim->get_reflection(damage.damage_type);
    size_t reflected_damage = (damage.damage_power / 100.0) * reflection; //get percent of reflected damage
    std::cout << "Victim tried to reflect damage, as a result reflected damage power : "
              << reflected_damage << std::endl;
    damage.damage_power -= reflected_damage;
    return Damage{damage.damage_type, reflected_damage, damage.piercing_power, 0};
}

void ActiveHeroState::take_reflected_damage(Character *attacker, Damage &reflected_dmg)
{
    if (can_dodge(attacker))
    {
        std::cout << "Attacker dodged from the reflected damage" << std::endl;
        return;
    }
    _take_damage(attacker, reflected_dmg);
    std::cout << "Attacker took the reflected damage" << std::endl;
}

void ActiveHeroState::try_to_create_critical_hit(Character *atacker, Damage &damage)
{
    size_t generated_critical_hit_chance = utils::rdtsc() % 100 + 1;
    if (generated_critical_hit_chance < atacker->get_parameter(parameter::critical_hit_chance))
    {
        damage.damage_power += damage.critical_damage_multiplier;
        std::cout << "Attacker created a critical hit, and damage power was increased on "
                  << damage.critical_damage_multiplier << " points " << std::endl;
    }
    else
    {
        std::cout << "Attacker was not able to create a critical hit" << std::endl;
    }
}

bool ActiveHeroState::take_remained_damage(Character *victim, Damage &dmg)
{
    int defense = victim->get_resistance(dmg.damage_type);

    defense -= dmg.piercing_power;
    std::cout << "Victim defense was pierced on "
                  << dmg.piercing_power << " points." << std::endl;

    if (static_cast<int>(dmg.damage_power) < defense)
    {
        std::cout << "Victim resisted the damage." << std::endl;
        return false;
    }
    else
    {
        dmg.damage_power -= defense;
        std::cout << "Victim decreased damage power on "
                  << defense << " points." << std::endl;
    }
    _take_damage(victim, dmg);
    return true;
}

void ActiveHeroState::reduce_time_to_next_move(Character *ch, size_t time)
{
    ch->increase_waiting_time(time);
}

bool ActiveHeroState::all_steps_done(Character* ch)
{
    return ch->get_characteristic(characteristic::initiative) == ch->get_time_to_next_move();
}

