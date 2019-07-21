#include "thing.h"

Thing::Thing(const std::string name) : m_durability(100), m_name(name)
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
