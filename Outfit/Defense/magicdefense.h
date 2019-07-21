#ifndef MAGICDEFENSE_H
#define MAGICDEFENSE_H

#include "defense.h"

class MagicDefense : public Defense
{
public:
    MagicDefense(const std::string &name, types resist_type, std::uint8_t resist_power) :
            Defense(name, resist_type, resist_power)
    {
        if (resist_type == types::physical)
        {
            throw std::runtime_error("Value error, type magic protection canno't be physical");
        }
    }

    void reduce_durability(unsigned int value)
    {
        return;
    }

};

#endif // MAGICDEFENSE_H
