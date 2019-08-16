#include <stdexcept>
#include "PhysicalDefense.h"
#include "Character.h"

PhysicalDefense::PhysicalDefense(const std::string &name, types resist_type, size_t resist_power) : Defense(name,
                                                                                                            resist_type,
                                                                                                            resist_power)
{
    if (resist_type != types::physical)
    {
        throw std::runtime_error("Value error, type of protection must be physical");
    }
}
