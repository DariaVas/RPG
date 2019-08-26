#include <stdexcept>
#include <plog/Log.h>
#include "MagicDefense.h"
#include "Character.h"

MagicDefense::MagicDefense(const std::string &name, damage_types resist_type, size_t resist_power) :
        Defense(name, resist_type, resist_power)
{
    if (resist_type == damage_types::physical)
    {
        throw std::runtime_error("Value error, damage_types magic protection cannot be physical");
    }

    LOGI << "Added magical defense : " << name
         << " resist type: " << static_cast<int>(resist_type)
         << " resist power: " << resist_power;
}

void MagicDefense::reduce_durability(unsigned int value)
{
    return;
}
