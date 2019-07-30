#pragma once
#ifndef INCREASECRITICALHITCHANCEDEFENSE_H
#define INCREASECRITICALHITCHANCEDEFENSE_H

#include "DefenseDecorator.h"
#include <iostream>
#include "Character/Character.h"
#include "Character/Parameters.h"

class IncreaseCriticalHitChanceDefense final : public DefenseDecorator
{

public:

    IncreaseCriticalHitChanceDefense(std::unique_ptr<Defense> &decorator, std::uint8_t value);
    
    void apply_effect(Character &character) override;

    void discard_effect(Character &character) override;

private:
    std::uint8_t m_increase_value;
};

#endif // INCREASECRITICALHITCHANCEDEFENSE_H
