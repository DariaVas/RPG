#pragma once
#ifndef INCREASERESISTANCETODAMAGE_H
#define INCREASERESISTANCETODAMAGE_H

#include "DefenseDecorator.h"

class IncreaseResistanceToDamage final : public DefenseDecorator
{
public:

    IncreaseResistanceToDamage(std::unique_ptr <Defense> &decorator, size_t value, damage_types damage_type);

    void apply_effect(Character *character) override;

    void discard_effect(Character *character) override;

private:
    damage_types m_damage_type;
    size_t m_resistance_power;
};

#endif // INCREASERESISTANCETODAMAGE_H
