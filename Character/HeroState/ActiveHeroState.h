#ifndef ACTIVEHEROSTATE_H
#define ACTIVEHEROSTATE_H

#include "HeroState.h"

class ActiveHeroState : public HeroState
{
public:
    ActiveHeroState();
    void damage(Character* ch);
    void take_damage(Character* ch, Damage& dmg);
};

#endif // ACTIVEHEROSTATE_H
