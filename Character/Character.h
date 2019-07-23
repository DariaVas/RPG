#ifndef CHARACTER_H
#define CHARACTER_H

#include "Character/Characterization.h"
#include "Character/Parameters.h"
#include "Outfit/Outfit.h"

class Character
{
public:
    Character(const Outfit& outfit, const Сharacterization& characterization);

    std::uint8_t get_characteristic(std::string feature_name);

    void set_characteristic(std::string feature_name, std::uint8_t feature_value);

    std::uint8_t get_parameter(std::string parameter_name);

    void set_parameter(std::string parameter_name, std::uint8_t parameter_value);

    void change_resistance(types resistance_type, int resistance_delta);
    void change_reflection_of_damage(types damage_type, int reflection_delta);
    void set_stun(std::uint8_t stun_seconds);

    void break_outfit(std::uint8_t breaking_value);

private:
    Сharacterization m_characterization;
    Parameters m_parameters;
    bool m_stunned;
    std::uint8_t m_stun_seconds;
    Outfit m_outfit;
};

#endif // CHARACTER_H
