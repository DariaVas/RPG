#include <iostream>
#include "plog/Log.h"
#include "Character.h"
#include "ActiveHeroState.h"
#include "StunnedHeroState.h"
#include "Utils.h"

Character::Character(Outfit &outfit, const CharacterizationObservable &characterization, const std::string &hero_name) :
        m_outfit(std::move(outfit)),
        m_characterization(characterization),
        m_parameters(hero_name, &m_characterization),
        m_hero_name(hero_name),
        m_hero_state(new ActiveHeroState()),
        m_waiting_time(0)
{
    m_characterization.add_observer(&m_parameters);
    check_outfit_overflow();
    m_outfit.apply_magic_effect(this);
    LOGI << "Hero : " << m_hero_name;

    LOGI << "Characteristic: \n"
         << "strength: " << m_characterization.get_characteristic(characteristic::strength) << "\n"
         << "sleight: " << m_characterization.get_characteristic(characteristic::sleight) << "\n"
         << "intelligence: " << m_characterization.get_characteristic(characteristic::intelligence) << "\n"
         << "physique: " << m_characterization.get_characteristic(characteristic::physique) << "\n"
         << "luck: " << m_characterization.get_characteristic(characteristic::luck) << "\n"
         << "initiative: " << m_characterization.get_characteristic(characteristic::initiative);

    LOGI << "Parameters: \n"
         << "HP: " << m_parameters.get_parameter(parameter::HP) << "\n"
         << "carried weight: " << m_parameters.get_parameter(parameter::carried_weight) << "\n"
         << "chance of dodge: " << m_parameters.get_parameter(parameter::dodge_chance) << "\n"
         << "chance of critical hit: " << m_parameters.get_parameter(parameter::critical_hit_chance);

    LOGI << "Reflection of damage: \n"
         << "physical: " << m_parameters.get_damage_reflection(damage_types::physical) << "\n"
         << "fire: " << m_parameters.get_damage_reflection(damage_types::fire) << "\n"
         << "ice: " << m_parameters.get_damage_reflection(damage_types::ice) << "\n"
         << "electric: " << m_parameters.get_damage_reflection(damage_types::electric) << "\n"
         << "acid: " << m_parameters.get_damage_reflection(damage_types::acid);

    LOGI << "Resistance to damage: \n"
         << "physical: " << m_parameters.get_damage_resistance(damage_types::physical) << "\n"
         << "fire: " << m_parameters.get_damage_resistance(damage_types::fire) << "\n"
         << "ice: " << m_parameters.get_damage_resistance(damage_types::ice) << "\n"
         << "electric: " << m_parameters.get_damage_resistance(damage_types::electric) << "\n"
         << "acid: " << m_parameters.get_damage_resistance(damage_types::acid);

}

void Character::increase_characteristic(characteristic feature, size_t feature_value)
{
    m_characterization.increase_characteristic(feature, feature_value);
}

void Character::decrease_characteristic(characteristic feature, size_t feature_value)
{
    m_characterization.decrease_characteristic(feature, feature_value);
    if(feature == characteristic::strength)
    {
        check_outfit_overflow();
    }
}

size_t Character::get_characteristic(characteristic feature)
{
    return m_characterization.get_characteristic(feature);
}

void Character::increase_parameter(parameter p, size_t value)
{
    m_parameters.increase_parameter(p, value);
}

void Character::decrease_parameter(parameter p, size_t value)
{
    m_parameters.decrease_parameter(p, value);
}

void Character::increase_resistance(damage_types resistance_type, size_t value)
{
    m_parameters.increase_resistance(resistance_type, value);
}

void Character::decrease_resistance(damage_types resistance_type, size_t value)
{
    m_parameters.decrease_resistance(resistance_type, value);
}

void Character::increase_reflection_of_damage(damage_types damage_type, size_t value)
{
    m_parameters.increase_reflection_of_damage(damage_type, value);
}

void Character::decrease_reflection_of_damage(damage_types damage_type, size_t value)
{
    m_parameters.decrease_reflection_of_damage(damage_type, value);
}


void Character::set_stun(bool is_stunned)
{
    if (is_stunned)
    {
        std::cout << m_hero_name << " is stunned since now" << std::endl;

        m_hero_state.reset(new StunnedHeroState());
    }
    else
    {
        std::cout << m_hero_name << " is active since now" << std::endl;

        m_hero_state.reset(new ActiveHeroState());
    }

}

void Character::break_outfit(size_t breaking_value)
{
    m_outfit.break_random_thing(this, breaking_value);
}

std::vector <Damage> Character::get_damages()
{
    if(m_waiting_time <  m_characterization.get_characteristic(characteristic::initiative))
    {
        throw std::logic_error("Character cannot generate damages until the time to the move comes");
    }
    m_waiting_time = 0;
    return m_hero_state->generate_damages(&m_outfit, this);
}

size_t Character::get_parameter(parameter p)
{
    return m_parameters.get_parameter(p);
}

const std::string &Character::get_hero_name()
{
    return m_hero_name;
}

size_t Character::get_resistance(damage_types resistance_type)
{
    return m_parameters.get_damage_resistance(resistance_type);
}

size_t Character::get_reflection(damage_types reflection_type)
{
    return m_parameters.get_damage_reflection(reflection_type);
}

bool Character::can_dodge()
{
    return m_hero_state->can_dodge(this);
}

Damage Character::try_to_reflect_damage(Damage &damage)
{
    return m_hero_state->try_to_reflect_damage(this, damage);
}

void Character::take_reflected_damage(Damage &reflected_dmg)
{
    m_hero_state->take_reflected_damage(this, reflected_dmg);
}

void Character::try_to_create_critical_hit(Damage &damage)
{
    m_hero_state->try_to_create_critical_hit(this, damage);
}

bool Character::take_remained_damage(Damage &dmg)
{
    return m_hero_state->take_remained_damage(this, dmg);
}

void Character::apply_effect_after_attack(Character *victim)
{
    m_outfit.apply_effect_after_attack(victim);
}

bool Character::all_steps_done()
{
    return m_hero_state->all_steps_done(this);
}

void Character::reduce_time_to_next_move(size_t time)
{
    m_hero_state->reduce_time_to_next_move(this, time);
}

void Character::increase_waiting_time(size_t time)
{
    m_waiting_time += time;
}

size_t Character::get_time_to_next_move()
{
    size_t initiative =  m_characterization.get_characteristic(characteristic::initiative);
    utils::safely_decrease_unsigned_value(initiative, m_waiting_time);
    return initiative;
}

void Character::check_outfit_overflow()
{
    while(m_parameters.get_parameter(parameter::carried_weight) < m_outfit.get_outift_weight())
    {
        m_outfit.lost_thing(this);
    }
}
