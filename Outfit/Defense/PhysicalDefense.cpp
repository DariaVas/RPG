#include <stdexcept>
#include <plog/Log.h>
#include "PhysicalDefense.h"
#include "Character.h"

PhysicalDefense::PhysicalDefense(const std::string &name, damage_types resist_type, size_t resist_power) : Defense(name,
                                                                                                                   resist_type,
                                                                                                                   resist_power)
{
    if (resist_type != damage_types::physical)
    {
        throw std::runtime_error("Value error, damage_types of protection must be physical");
    }
    LOGI << "Added physical defense : " << name
         << " resist type: " << static_cast<int>(resist_type)
         << " resist power: " << resist_power;
}
