#include "defense.h"
#include "damage.h"
#include "Character.h"

Defense::Defense(const std::string &name, types resist_type, std::uint8_t resist_power) :
        Thing(name),
        m_resist_type(resist_type),
        m_resist_power(resist_power)
{
}

void Defense::apply_effect(Character &character)
{
    character.change_resistance(m_resist_type, m_resist_power);
}

void Defense::discard_effect(Character &character)
{
    character.change_resistance(m_resist_type, -m_resist_power);
}

types Defense::get_resist_type()
{
    return m_resist_type;
}

std::uint8_t Defense::get_resist_power()
{
    return m_resist_power;
}

Defense::~Defense()
{
    
}
