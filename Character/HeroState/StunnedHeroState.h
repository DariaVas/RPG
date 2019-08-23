#ifndef STUNNEDHEROSTATE_H
#define STUNNEDHEROSTATE_H

#include "HeroState.h"

class StunnedHeroState : public HeroState
{
public:
    StunnedHeroState();
    bool can_dodge(Character* victim) override;
    Damage try_to_reflect_damage(Character* victim, Damage& damage) override;
    void take_reflected_damage(Character* attacker, Damage& reflected_dmg) override;
    void try_to_resist_damage(Character* victim, Damage& damage) override;
    void try_to_create_critical_hit(Character* atacker, Damage& damage) override;
    bool take_remained_damage(Character* victim, Damage &dmg) override;
};

#endif // STUNNEDHEROSTATE_H
