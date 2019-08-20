#ifndef HEROSTATE_H
#define HEROSTATE_H
#include "Damage.h"

class Character;

class HeroState
{
public:
    virtual void damage (Character* ch) = 0;
    virtual void take_damage(Character* ch, Damage& damage) = 0;
    virtual ~HeroState() = default;
};

#endif // HEROSTATE_H
