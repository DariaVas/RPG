#ifndef RPG_GAMECREATOR_H
#define RPG_GAMECREATOR_H
#include "HeroBuilder/HeroBuilder.h"

class GameCreator
{
public:
    virtual HeroBuilder* get_hero_builder() = 0;
    virtual ~GameCreator() = default;
};


#endif //RPG_GAMECREATOR_H
