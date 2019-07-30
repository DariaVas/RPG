#pragma once
#ifndef INCREASECHANCEOFDOBGE_H
#define INCREASECHANCEOFDOBGE_H

#include "DefenseDecorator.h"

class IncreaseChanceOfDobge final : public DefenseDecorator
{
public:
    IncreaseChanceOfDobge(std::unique_ptr<Defense> &decorator, std::uint8_t value);

    void apply_effect(Character &character) override;
    void discard_effect(Character &character) override;

private:
    std::uint8_t m_dobge_power;
};

#endif // INCREASECHANCEOFDOBGE_H
