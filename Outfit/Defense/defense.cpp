#include <iostream>
#include "defense.h"
#include "damage.h"
#include "Character.h"

Defense::Defense(const std::string &name, types resist_type, size_t resist_power) :
        Thing(name),
        m_resist_type(resist_type),
        m_resist_power(resist_power)
{
}

void Defense::apply_effect(Character &character)
{
    std::cout << "Thing: " << this->get_name() << ", applying defense effect"
              << " points to increase : " << m_resist_power
              << " resist type : " << m_resist_type << std::endl;
    character.change_resistance(m_resist_type, m_resist_power);
    std::cout << "Thing: " << this->get_name() << ", applied defense effect" << std::endl;
}

void Defense::discard_effect(Character &character)
{
    std::cout << "Thing: " << this->get_name() << " ,discarding defense effect"
              << " points to decrease : " << m_resist_power
              << " resist type : " << m_resist_type << std::endl;

    character.change_resistance(m_resist_type, -m_resist_power);
    std::cout << "Thing: " << this->get_name() << " ,discarded defense effect" << std::endl;
}

types Defense::get_resist_type()
{
    return m_resist_type;
}

size_t Defense::get_resist_power()
{
    return m_resist_power;
}

Defense::~Defense()
{

}
