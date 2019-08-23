#include <iostream>
#include "ActiveHeroState.h"
#include "Character.h"

ActiveHeroState::ActiveHeroState()
{

}

//void ActiveHeroState::damage(Character* ch)
//{
//    // Add code
//}

//void ActiveHeroState::take_damage(Character* ch, Damage& dmg)
//{
//    //Add code
//}

bool ActiveHeroState::can_dodge(Character* victim)
{
    size_t generated_dodge_chance = rand() % 100 + 1;
    size_t hero_dodge_chance = victim->get_parameter(parameter::dodge_chance);
    std::cout << victim->get_hero_name() << " is trying to dodge, his dodge chance: " << hero_dodge_chance
              << " generated dodge chance : " << generated_dodge_chance << std::endl;
    if(generated_dodge_chance < hero_dodge_chance)
    {
        std::cout << victim->get_hero_name() << " dodged damage"<<std::endl;
        return true;
    }
    std::cout << victim->get_hero_name() << " didn't dodge damage"<<std::endl;
    return false;
}

Damage ActiveHeroState::try_to_reflect_damage(Character* victim, Damage& damage)
{
    size_t reflection = victim->get_reflection(damage.damage_type);
    size_t reflected_damage = (damage.damage_power / 100.0) * reflection; //get percent of reflected damage
    std::cout << victim->get_hero_name() << "tried to reflect damage, as a result reflected damage power : " << reflected_damage<<std::endl;
    return Damage{damage.damage_type, reflected_damage, damage.piercing_power, 0};
}

void ActiveHeroState::take_reflected_damage(Character* attacker, Damage& reflected_dmg)
{
    if(can_dodge(attacker))
    {
        std::cout << attacker->get_hero_name() << " dodged reflected damage";
        return;
    }

    // just take the reflected damage
}

void ActiveHeroState::try_to_resist_damage(Character* victim, Damage& damage)
{
    
}

void ActiveHeroState::try_to_create_critical_hit(Character *atacker, Damage &damage)
{
    size_t generated_critical_hit_chance = rand() % 100 + 1;
    if(generated_critical_hit_chance < atacker->get_parameter(parameter::critical_hit_chance))
    {
        damage.damage_power += damage.critical_damage_multiplier;
        std::cout << atacker->get_hero_name() << " created a critical hit, and damage power was increased on "
                  << damage.critical_damage_multiplier << " points " << std::endl;
    }
}

bool ActiveHeroState::take_remained_damage(Character* victim, Damage &dmg)
{
    size_t defense = victim->get_resistance(dmg.damage_type);
    if(defense < dmg.piercing_power)
    {
        defense = 0;
    }
    else
    {
        defense -= dmg.piercing_power;
    }
    
    if (dmg.damage_power < defense)
    {
        dmg.damage_power = 0;
        // the damage was deflected
        return false;
    }
    else
    {
        dmg.damage_power -= defense;
    }
    _take_damage(victim,dmg);
    return true;
}
