#pragma once

#ifndef MAGICDEFENSE_H
#define MAGICDEFENSE_H

#include "defense.h"

class MagicDefense final : public Defense
{
public:
    MagicDefense(const std::string &name, types resist_type, std::uint8_t resist_power);

    void reduce_durability(unsigned int value) override;
    ~MagicDefense() override = default;
};

#endif // MAGICDEFENSE_H
