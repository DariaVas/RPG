#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <stdexcept>
#include "Game.h"
#include "Utils.h"

Game::Game(std::unique_ptr <GameCreator> &game_creator)
        : m_heroes_builder(game_creator->get_hero_builder()),
          m_first_hero(m_heroes_builder->build_first_hero()),
          m_second_hero(m_heroes_builder->build_second_hero())
{
}

void Game::play()
{

    size_t round = 0;
    Character *initiator = &m_first_hero;
    Character *passive_hero = &m_second_hero;
    check_lives(initiator, passive_hero);
    while (true)
    {
        std::cout << "-----------------------------------------\n\n";
        std::cout << "Round № " << ++round << std::endl;
        std::cout << "-----------------------------------------\n";
        play_raund(initiator, passive_hero);
        std::swap(initiator, passive_hero);
    }
}

void Game::play_raund(Character *initiator, Character *passive_hero)
{
    do
    {
        size_t minimal_time = std::min(initiator->get_time_to_next_move(), passive_hero->get_time_to_next_move());

        initiator->reduce_time_to_next_move(minimal_time);
        passive_hero->reduce_time_to_next_move(minimal_time);

        if(initiator->get_time_to_next_move() == 0 && passive_hero->get_time_to_next_move() == 0)
        {
           fight(initiator, passive_hero);
           fight(passive_hero, initiator);
           
        }
        else 
        {
            fight(( initiator->get_time_to_next_move() == 0 ? initiator :  passive_hero),
                  ( initiator->get_time_to_next_move() == 0 ? passive_hero :  initiator));
        }
    }while(!initiator->all_steps_done() || !passive_hero->all_steps_done());
}

void Game::fight(Character* attacker, Character* victim)
{
    
    std::cout << "\n\n*****************************************\n";
    std::cout << "Attacker: " << attacker->get_hero_name() << " HP: " << attacker->get_parameter(parameter::HP) << "\n"
              << "Victim: " << victim->get_hero_name() << " HP: " << victim->get_parameter(parameter::HP) << std::endl;
    std::cout << "*****************************************\n";

    auto damages = attacker->get_damages();
    for (auto &damage : damages)
    {
        std::cout << "--> Attacker generated a damage: \n"
                  << "damage type: " << static_cast<std::underlying_type<damage_types>::type>(damage.damage_type)
                  << "\n"
                  << "damage power: " << damage.damage_power << "\n"
                  << "piercing power of damage: " << damage.piercing_power << "\n"
                  << "critical damage multiplier: " << damage.critical_damage_multiplier << std::endl;

        std::cout << "1. Attacker is trying to create critical hit. " << std::endl;
        attacker->try_to_create_critical_hit(damage);

        std::cout << "2. Victim is trying to dodge." << std::endl;
        if (victim->can_dodge())
        {
            std::cout << "Victim dodged from the damage." << std::endl;
            continue;
        }

        std::cout << "Victim didn't dodge from the damage." << std::endl;

        std::cout << "3. Victim is trying to reflect the damage." << std::endl;

        Damage reflected_damage(victim->try_to_reflect_damage(damage));

        if (reflected_damage.damage_power)
        {
            std::cout << "Victim has reflected " << reflected_damage.damage_power << " points of damage power."
                      << "Remained damage: " << damage.damage_power
                      << std::endl;
            std::cout << "Attacker has to take reflected damage. " << std::endl;
            attacker->take_reflected_damage(reflected_damage);
        }
        else
        {
            std::cout << "Victim couldn't reflect the damage." << std::endl;
        }

        if (!damage.damage_power)
        {
            std::cout << "Victim reflected all damage. " << std::endl;
            continue;
        }

        std::cout << "4. Victim is trying to resist the damage." << std::endl;

        if (victim->take_remained_damage(damage))
        {
            attacker->apply_effect_after_attack(victim);
            std::cout << "Victim took the damage. Magic effects after attack were applied." << std::endl;
        }
        else
        {
            std::cout << "Victim didn't take the damage." << std::endl;
        }
        check_lives(attacker, victim);
    }
}

void Game::check_lives(Character *attacker, Character *victim)
{
    size_t a_hp = attacker->get_parameter(parameter::HP);
    size_t v_hp = victim->get_parameter(parameter::HP);
    if(a_hp == 0 && v_hp == 0)
    {
        throw utils::HeroDied("both heroes");
    }
    else if(a_hp == 0)
    {
        throw utils::HeroDied(attacker->get_hero_name());
    }
    else if(v_hp == 0)
    {
        throw utils::HeroDied(victim->get_hero_name());
    }
}
