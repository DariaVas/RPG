#pragma once

#ifndef PHYSICALDEFENSE_H
#define PHYSICALDEFENSE_H

#include "defense.h"

class PhysicalDefense : public Defense
{
public:
    PhysicalDefense(const std::string &name, types resist_type, std::uint8_t resist_power);

};

#endif // PHYSICALDEFENSE_H
