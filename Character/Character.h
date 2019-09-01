#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include "CharacterizationObservable.h"
#include "Parameters.h"
#include "Outfit.h"
#include "HeroState.h"


class Character
{
public:
    Character(Outfit &outfit, const CharacterizationObservable &characterization, const std::string &hero_name);

    size_t get_characteristic(characteristic feature);

    void increase_characteristic(characteristic feature, size_t feature_value);

    void decrease_characteristic(characteristic feature, size_t feature_value);

    void increase_parameter(parameter p, size_t value);

    void decrease_parameter(parameter p, size_t value);

    size_t get_parameter(parameter p);

    void increase_resistance(damage_types resistance_type, size_t value);

    void decrease_resistance(damage_types resistance_type, size_t value);

    size_t get_resistance(damage_types resistance_type);

    void increase_reflection_of_damage(damage_types damage_type, size_t value);

    void decrease_reflection_of_damage(damage_types damage_type, size_t value);

    size_t get_reflection(damage_types reflection_type);

    void set_stun(bool is_stunned);

    void break_outfit(size_t breaking_value);

    const std::string &get_hero_name();

    std::vector <Damage> get_damages();

    bool can_dodge();

    Damage try_to_reflect_damage(Damage &damage);

    void take_reflected_damage(Damage &reflected_dmg);

    void try_to_create_critical_hit(Damage &damage);

    bool take_remained_damage(Damage &dmg);

    void apply_effect_after_attack(Character *victim);
    
    bool all_steps_done();
    
    void reduce_time_to_next_move(size_t time);

    void set_time_to_next_move(size_t time);
    
    size_t get_time_to_next_move();

private:
    void check_outfit_overflow();
private:
    Outfit m_outfit;
    CharacterizationObservable m_characterization;
    Parameters m_parameters;
    const std::string m_hero_name;
    std::unique_ptr <HeroState> m_hero_state;
    size_t m_time_to_next_move;
};

#endif // CHARACTER_H
