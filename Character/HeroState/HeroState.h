#ifndef HEROSTATE_H
#define HEROSTATE_H

#include <vector>
#include "Damage.h"

class Character;
class Outfit;

class HeroState
{
public:
    virtual std::vector<Damage> generate_damages(Outfit *outfit, Character *ch) = 0;

    virtual bool can_dodge(Character *victim) = 0;

    virtual Damage try_to_reflect_damage(Character *victim, Damage &damage) = 0;

    virtual void take_reflected_damage(Character *attacker, Damage &reflected_dmg) = 0;

    virtual void try_to_create_critical_hit(Character *atacker, Damage &damage) = 0;

    virtual bool take_remained_damage(Character *victim, Damage &dmg) = 0;

    virtual ~HeroState() = default;

protected:
    void _take_damage(Character *victim, Damage &dmg);
};

#endif // HEROSTATE_H
