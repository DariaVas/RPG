#pragma once

#ifndef MAGICDEFENSE_H
#define MAGICDEFENSE_H

#include "Defense.h"

class MagicDefense final : public Defense
{
public:
    MagicDefense(const std::string &name, damage_types resist_type, size_t resist_power);

    void reduce_durability(unsigned int value) override;

    ~MagicDefense() override = default;
};

#endif // MAGICDEFENSE_H
