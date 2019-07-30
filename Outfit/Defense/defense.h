#pragma once

#ifndef DEFENSE_H
#define DEFENSE_H

#include "thing.h"
#include "damage.h"

class Character;

class Defense : public Thing
{
public:
    Defense(const std::string &name, types resist_type, std::uint8_t resist_power);
    void apply_effect(Character &character) override;
    void discard_effect(Character &character) override;
    types get_resist_type();
    std::uint8_t get_resist_power();
    virtual ~Defense()=0;
private:
    types m_resist_type;
    std::uint8_t m_resist_power;
};

#endif // DEFENSE_H
