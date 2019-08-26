#ifndef RPG_GAME_H
#define RPG_GAME_H

#include "GameCreator.h"
#include "Character.h"

class Game
{
public:
    explicit Game(std::unique_ptr <GameCreator> &game_creator);

    void play();

private:
    std::unique_ptr <HeroBuilder> m_heroes_builder;
    Character m_first_hero;
    Character m_second_hero;
};


#endif //RPG_GAME_H
