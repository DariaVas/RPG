#include <plog/Log.h>
#include "Defense.h"
#include "Damage.h"
#include "Character.h"

Defense::Defense(const std::string &name, damage_types resist_type, size_t resist_power) :
        Thing(name),
        m_resist_type(resist_type),
        m_resist_power(resist_power)
{
}

void Defense::apply_effect(Character *character)
{
    LOGI << "Thing: " << this->get_name() << ", applying defense effect"
              << " points to increase : " << m_resist_power
              << " resist damage_types : " << static_cast<std::underlying_type<damage_types>::type>(m_resist_type);
    character->increase_resistance(m_resist_type, m_resist_power);
    LOGI << "Thing: " << this->get_name() << ", applied defense effect" ;
}

void Defense::discard_effect(Character *character)
{
    LOGI << "Thing: " << this->get_name() << " ,discarding defense effect"
              << " points to decrease : " << m_resist_power
              << " resist damage_types : " << static_cast<std::underlying_type<damage_types>::type>(m_resist_type);

    character->decrease_resistance(m_resist_type, m_resist_power);
    LOGI << "Thing: " << this->get_name() << " ,discarded defense effect";
}

damage_types Defense::get_resist_type()
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
