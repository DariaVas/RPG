#include <plog/Log.h>
#include "Thing.h"
#include "Utils.h"
#include "Character.h"

Thing::Thing(const std::string &name) : m_durability(100), m_name(name), m_weight(10)
{

}

void Thing::reduce_durability(unsigned int value)
{
    utils::safely_decrease_unsigned_value(m_durability, value);
    if (m_durability == 0)
    {
        LOGI << "The thing " << m_name << " has been broken";
    }
    else
    {
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
