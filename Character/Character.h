#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include "CharacterizationObservable.h"
#include "Parameters.h"
#include "Outfit.h"


class Character
{
public:
    Character(Outfit &outfit, const CharacterizationObservable &characterization);

    size_t get_characteristic(std::string feature_name);

    void increase_characteristic(std::string feature_name, size_t feature_value);

    void decrease_characteristic(std::string feature_name, size_t feature_value);

    void increase_parameter(parameter p, size_t value);

    void decrease_parameter(parameter p, size_t value);

    void increase_resistance(types resistance_type, int value);

    void decrease_resistance(types resistance_type, int value);

    void increase_reflection_of_damage(types damage_type, int value);

    void decrease_reflection_of_damage(types damage_type, int value);

    void set_stun(size_t stun_seconds);

    void break_outfit(size_t breaking_value);

private:
    Outfit m_outfit;
    CharacterizationObservable m_characterization;
    Parameters m_parameters;
    bool m_stunned;
    size_t m_stun_seconds;
};

#endif // CHARACTER_H
