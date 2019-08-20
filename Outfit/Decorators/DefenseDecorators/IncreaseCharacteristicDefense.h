#pragma once
#ifndef INCREASECHARACTERISTICDEFENSE_H
#define INCREASECHARACTERISTICDEFENSE_H

#include <iostream>
#include "DefenseDecorator.h"
#include "Character.h"

class IncreaseCharacteristicDefense final : public DefenseDecorator
{
public:

    IncreaseCharacteristicDefense(std::unique_ptr <Defense> &decorator, size_t value, characteristic characteristic);

    void apply_effect(Character *character) override;

    void discard_effect(Character *character) override;

private:
    characteristic m_characteristic;
    size_t m_value;
};

#endif // INCREASECHARACTERISTICDEFENSE_H
