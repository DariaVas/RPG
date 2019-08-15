#include <stdexcept>
#include "MagicDefense.h"

MagicDefense::MagicDefense(const std::string &name, types resist_type, size_t resist_power) :
        Defense(name, resist_type, resist_power)
{
    if (resist_type == types::physical)
    {
        throw std::runtime_error("Value error, type magic protection cannot be physical");
    }
}

void MagicDefense::reduce_durability(unsigned int value)
{
    return;
}
