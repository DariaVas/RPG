#ifndef RPG_GAME_H
#define RPG_GAME_H

#include "GameCreator.h"
#include "Character.h"

class Game
{
public:
    explicit Game(std::unique_ptr<GameCreator>& game_creator);
    void play();
private:
    bool can_dodge(Character* victim);
    void try_to_create_critical_hit(Character* atacker, Damage& damage);
    Damage try_to_reflect_damage(Character* victim, Damage& damage);
    void take_reflected_damage(Character* attacker, Damage& reflected_dmg);
    void try_to_resist_damage(Character* victim, Damage& damage);
    void try_to_pierce_defense(Character* attacker, Character* victim);
private:
    std::unique_ptr<HeroBuilder> m_heroes_builder;
    Character m_first_hero;
    Character m_second_hero;
};


#endif //RPG_GAME_H
