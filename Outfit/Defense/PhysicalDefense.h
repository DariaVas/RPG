#pragma once

#ifndef PHYSICALDEFENSE_H
#define PHYSICALDEFENSE_H

#include "Defense.h"

class PhysicalDefense : public Defense
{
public:
    PhysicalDefense(const std::string &name, damage_types resist_type, size_t resist_power);

};

#endif // PHYSICALDEFENSE_H
