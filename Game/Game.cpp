#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include "Game.h"

Game::Game(std::unique_ptr <GameCreator> &game_creator)
        : m_heroes_builder(game_creator->get_hero_builder()),
          m_first_hero(m_heroes_builder->build_first_hero()),
          m_second_hero(m_heroes_builder->build_second_hero())
{
}

void Game::play()
{
    Character *attacker = &m_first_hero;
    Character *victim = &m_second_hero;
    size_t round = 0;
    while (true)
    {
        std::cout << "-----------------------------------------\n\n";
        std::cout << "Round № " << ++round << std::endl;
        std::cout << "-----------------------------------------\n";
        std::swap(attacker, victim);

        std::cout << "Attacker: " << attacker->get_hero_name() << " HP: " << attacker->get_parameter(parameter::HP)
                  << "\n"
                  << "Victim: " << victim->get_hero_name() << " HP: " << victim->get_parameter(parameter::HP)
                  << std::endl;

        auto damages = attacker->get_damages();
        for (auto &damage : damages)
        {
            std::cout << "Attacker generated a damage: \n"
                      << "  damage type: " << static_cast<std::underlying_type<damage_types>::type>(damage.damage_type)
                      << "  \n"
                      << "  damage power: " << damage.damage_power << "\n"
                      << "  piercing power of damage: " << damage.piercing_power << "\n"
                      << "  critical damage multiplier: " << damage.critical_damage_multiplier << std::endl;


            attacker->try_to_create_critical_hit(damage);

            if (victim->can_dodge())
            {
                std::cout << "Victim dodged from the damage." << std::endl;
                continue;
            }

            std::cout << victim->get_hero_name() << " didn't dodge from the damage." << std::endl;


            Damage reflected_damage(victim->try_to_reflect_damage(damage));

            if (reflected_damage.damage_power)
            {
                std::cout << "Victim has reflected " << reflected_damage.damage_power << " points of damage power."
                          << std::endl;
                attacker->take_reflected_damage(reflected_damage);
            } else
            {
                std::cout << victim->get_hero_name() << " couldn't reflect the damage." << std::endl;
            }

            if (!damage.damage_power)
            {
                continue;
            }

            if (victim->take_remained_damage(damage))
            {
                attacker->apply_effect_after_attack(victim);
                std::cout << "Victim took the damage. Magic effects after attack were applied." << std::endl;
            }
            if (victim->get_parameter(parameter::HP) == 0)
            {
                std::cout << victim->get_hero_name() << " died, " << attacker->get_hero_name() << " won!" << std::endl;
                return;
            } else if (attacker->get_parameter(parameter::HP) == 0)
            {
                std::cout << attacker->get_hero_name() << " died, " << victim->get_hero_name() << " won!" << std::endl;
                return;
            }
        }
    }
}

