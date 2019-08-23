#include <stdlib.h>
#include <iostream>
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
            attacker->try_to_create_critical_hit(damage);

            if(victim->can_dodge())
            {
                continue;
            }
            Damage reflected_damage(victim->try_to_reflect_damage(damage));
            if(reflected_damage.damage_power)
            {
                attacker->take_reflected_damage(reflected_damage);
            }
            else
            {
                std::cout << victim->get_hero_name() << " was not able to reflect the damage" << std::endl;
            }

            if(!damage.damage_power)
            {
                continue;
            }
            
            if(victim->take_remained_damage(dmg))
            {
                attacker->apply_effect_after_attack(victim);
            }
                        
        }
    }
}

