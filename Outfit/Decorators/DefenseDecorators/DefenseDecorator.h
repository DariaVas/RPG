#pragma once
#ifndef DEFENSEDECORATOR_H
#define DEFENSEDECORATOR_H

#include "defense.h"
#include <iostream>
#include <memory>

class DefenseDecorator : public Defense
{
public:
    DefenseDecorator(std::unique_ptr<Defense>& decorator) :
            Defense(decorator->get_name(), decorator->get_resist_type(),
                    decorator->get_resist_power()),
            m_decorator(std::move(decorator))
    {

    }

    void apply_effect(Character &character) override
    {
        m_decorator.apply_effect(character);
    }

    void discard_effect(Character &character) override
    {
        m_decorator.apply_effect(character);
    }

    virtual ~DefenseDecorator() = 0;

protected:
    std::unique_ptr<Defense> m_decorator;
};

#endif // DEFENSEDECORATOR_H
