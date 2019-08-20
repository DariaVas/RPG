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
    Character(Outfit &outfit, const CharacterizationObservable &characterization, const std::string& hero_name);

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

    void set_stun(size_t stun_seconds);

    void break_outfit(size_t breaking_value);

    const std::string& get_hero_name();

    std::vector<Damage> get_damages();

private:
    Outfit m_outfit;
    CharacterizationObservable m_characterization;
    Parameters m_parameters;
    std::string m_hero_name;
    std::unique_ptr<HeroState> m_hero_state;
    bool m_stunned;
    size_t m_stun_seconds;
};

#endif // CHARACTER_H
