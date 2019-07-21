#ifndef PHYSICALDEFENSE_H
#define PHYSICALDEFENSE_H

#include "defense.h"

class PhysicalDefense : public Defense
{
public:
    PhysicalDefense(const std::string &name, types resist_type, std::uint8_t resist_power) : Defense(name, resist_type,
                                                                                                     resist_power)
    {
        if (resist_type != types::physical)
        {
            throw std::runtime_error("Value error, type of protection must be physical");
        }
    }

};

#endif // PHYSICALDEFENSE_H
