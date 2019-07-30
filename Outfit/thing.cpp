#include "thing.h"
#include "Character.h"

Thing::Thing(const std::string &name) : m_durability(100), m_name(name)
{

}

void Thing::reduce_durability(unsigned int value)
{
    if (value > m_durability)
    {
        m_durability = 0;
    } else
    {
        m_durability -= value;
    }
}

bool Thing::is_broken()
{
    return m_durability == 0;
}

std::uint8_t Thing::get_durability()
{
    return m_durability;
}

std::string Thing::get_name()
{
    return m_name;
}
