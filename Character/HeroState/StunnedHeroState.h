#ifndef STUNNEDHEROSTATE_H
#define STUNNEDHEROSTATE_H

#include "HeroState.h"

class StunnedHeroState : public HeroState
{
public:
    StunnedHeroState();
    void damage(Character* ch);
    void take_damage(Character* ch, Damage& dmg);
};

#endif // STUNNEDHEROSTATE_H
