#ifndef DEFENSEDECORATOR_H
#define DEFENSEDECORATOR_H

#include "defense.h"
#include <iostream>

class DefenseDecorator : public Defense
{
public:
    DefenseDecorator(Defense &decorator) :
            Defense(decorator),
            m_decorator(decorator)
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
    Defense &m_decorator;
};

#endif // DEFENSEDECORATOR_H
