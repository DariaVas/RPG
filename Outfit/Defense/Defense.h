#pragma once

#ifndef DEFENSE_H
#define DEFENSE_H

#include "Thing.h"
#include "Damage.h"

class Character;

class Defense : public Thing
{
public:
    Defense(const std::string &name, damage_types resist_type, size_t resist_power);

    virtual void apply_effect(Character *character) override;

    virtual void discard_effect(Character *character) override;

    virtual damage_types get_resist_type();

    virtual size_t get_resist_power();

    virtual ~Defense() = 0;

private:
    damage_types m_resist_type;
    size_t m_resist_power;
};

#endif // DEFENSE_H
