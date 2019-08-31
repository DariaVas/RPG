#include <plog/Log.h>
#include "Thing.h"
#include "Character.h"

Thing::Thing(const std::string &name) : m_durability(100), m_name(name), m_weight(100)
{

}

void Thing::reduce_durability(unsigned int value)
{
    if (value > m_durability)
    {
        m_durability = 0;
        LOGI << "The thing " << m_name << " is already broken";
    }
    else
    {
        m_durability -= value;
        LOGI << "The durability of " << m_name << " was reduced to " << m_durability << " points";
    }
}

bool Thing::is_broken()
{
    return m_durability == 0;
}

size_t Thing::get_durability()
{
    return m_durability;
}

const std::string& Thing::get_name()
{
    return m_name;
}

size_t Thing::get_weight()
{
    return m_weight;
}
