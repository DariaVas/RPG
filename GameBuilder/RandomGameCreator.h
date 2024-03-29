#pragma once
#ifndef RPG_RANDOMGAMECREATOR_H
#define RPG_RANDOMGAMECREATOR_H

#include "RandomHeroBuilder.h"
#include "IGameCreator.h"

class RandomGameCreator : public IGameCreator
{
public:
    HeroBuilder *get_hero_builder()
    {

        return new RandomHeroBuilder();
    }
};


#endif //RPG_RANDOMGAMECREATOR_H
