#include <stdlib.h>
#include "Game.h"

Game::Game(std::unique_ptr<GameCreator>& game_creator)
    : m_heroes_builder(game_creator->get_hero_builder()),
      m_first_hero(m_heroes_builder->build_first_hero()),
      m_second_hero(m_heroes_builder->build_second_hero())
{
}

void Game::play()
{
    Character* attacker = &m_first_hero;
    Character* victim = &m_second_hero;

    while (true)
    {
        auto damages = attacker->get_damages();
        for (auto& damage : damages)
        {
            try_to_create_critical_hit(attacker,damage);

            if(can_dodge(victim))
            {
                continue;
            }
            Damage reflected_damage(try_to_reflect_damage(victim, damage));
            if(reflected_damage.damage_power)
            {
                take_reflected_damage(attacker, reflected_damage);
            }
            else
            {
                std::cout << victim->get_hero_name() << " was not able to reflect the damage" << std::endl;
            }

            if(!damage.damage_power)
            {
                continue;
            }
        }
    }
}

bool Game::can_dodge(Character* victim)
{
    size_t generated_dodge_chance = rand() % 100 + 1;
    size_t hero_dodge_chance = victim->get_characteristic(parameter::dodge_chance);
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

Damage Game::try_to_reflect_damage(Character* victim, Damage& damage)
{
    size_t reflection = victim->get_reflection(damage.damage_type);
    size_t reflected_damage = (damage.damage_power / 100.0) * reflection; //get percent of reflected damage
    std::cout << victim->get_hero_name() << "tried to reflect damage, as a result reflected damage power : " << reflected_damage<<std::endl;
    return Damage(damage.damage_type, reflected_damage, damage.piercing_power, 0);
}

void Game::take_reflected_damage(Character* attacker, Damage& reflected_dmg)
{
    if(can_dodge(attacker))
    {
        std::cout << attacker->get_hero_name() << " dodged reflected damage";
        return;
    }

    // just take the reflected damage

}

void Game::try_to_resist_damage(Character* victim, Damage& damage)
{

}

void Game::try_to_create_critical_hit(Character* atacker, Damage& damage)
{
    size_t generated_critical_hit_chance = rand() % 100 + 1;
    if(generated_critical_hit_chance < atacker->get_parameter(parameter::critical_hit_chance))
    {
        damage.damage_power += damage.critical_damage_multiplier;
        std::cout << atacker->get_hero_name() << " created a critical hit, and damage power was increased on "
                  << damage.critical_damage_multiplier << " points " << std::endl;
    }
}

void Game::try_to_pierce_defense(Character* attacker, Character* victim)
{

}

