#pragma once
#ifndef DEFENSEDECORATOR_H
#define DEFENSEDECORATOR_H

#include <iostream>
#include <memory>
#include "Defense.h"

class DefenseDecorator : public Defense
{
public:
    DefenseDecorator(std::unique_ptr <Defense> &defense);

    virtual void apply_effect(Character *character) override;

    virtual void discard_effect(Character *character) override;

    virtual void reduce_durability(unsigned int value) override;

    damage_types get_resist_type() override;

    size_t get_resist_power() override;

    bool is_broken() override;

    const std::string& get_name() override;

    size_t get_weight() override;

    virtual ~DefenseDecorator() = 0;

protected:
    std::unique_ptr <Defense> m_defense;
};

#endif // DEFENSEDECORATOR_H
