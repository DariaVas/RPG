#ifndef STUNNEDHEROSTATE_H
#define STUNNEDHEROSTATE_H

#include "HeroState.h"

class StunnedHeroState : public HeroState
{
public:
    StunnedHeroState();

    std::vector <Damage> generate_damages(Outfit *outfit, Character *ch) override;

    bool can_dodge(Character *victim) override;

    Damage try_to_reflect_damage(Character *victim, Damage &damage) override;

    void take_reflected_damage(Character *attacker, Damage &reflected_dmg) override;

    void try_to_create_critical_hit(Character *atacker, Damage &damage) override;

    bool take_remained_damage(Character *victim, Damage &dmg) override;

    void reduce_time_to_next_move(Character *ch, size_t time) override;

    bool all_steps_done(Character *ch) override;
private:
    void change_state_if_the_times_came(Character *ch);

private:
    size_t m_stun_seconds;
};

#endif // STUNNEDHEROSTATE_H
