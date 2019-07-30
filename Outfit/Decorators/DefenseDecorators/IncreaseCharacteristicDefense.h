#pragma once
#ifndef INCREASECHARACTERISTICDEFENSE_H
#define INCREASECHARACTERISTICDEFENSE_H

#include <iostream>
#include "DefenseDecorator.h"
#include "Character/Character.h"

class IncreaseCharacteristicDefense final : public DefenseDecorator
{
public:

    IncreaseCharacteristicDefense(std::unique_ptr<Defense>& decorator, std::uint8_t value, std::string characteristic);

    void apply_effect(Character &character) override;
    void discard_effect(Character &character) override;

private:
    std::string m_characteristic_name;
    std::uint8_t m_value;
};

#endif // INCREASECHARACTERISTICDEFENSE_H