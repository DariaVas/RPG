#pragma once
#ifndef DEFENSEDECORATOR_H
#define DEFENSEDECORATOR_H

#include "defense.h"
#include <iostream>
#include <memory>

class DefenseDecorator : public Defense
{
public:
    DefenseDecorator(std::unique_ptr<Defense>& decorator);

    void apply_effect(Character &character);

    void discard_effect(Character &character);
    virtual ~DefenseDecorator() = 0;

protected:
    std::unique_ptr<Defense> m_decorator;
};

#endif // DEFENSEDECORATOR_H
