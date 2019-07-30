#pragma once
#ifndef INCREASEREFLECTIONOFDAMAGE_H
#define INCREASEREFLECTIONOFDAMAGE_H

#include "DefenseDecorator.h"

class IncreaseReflectionOfDamage final : public DefenseDecorator
{
public:

    IncreaseReflectionOfDamage(std::unique_ptr<Defense> &decorator, std::uint8_t value, types damage_type);
    
    void apply_effect(Character &character) override;

    void discard_effect(Character &character) override;

private:
    types m_damage_type;
    std::uint8_t m_reflection_power;
};

#endif // INCREASEREFLECTIONOFDAMAGE_H