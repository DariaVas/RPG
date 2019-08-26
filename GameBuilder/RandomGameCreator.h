#pragma once
#ifndef RPG_RANDOMGAMECREATOR_H
#define RPG_RANDOMGAMECREATOR_H

#include "RandomHeroBuilder.h"
#include "GameCreator.h"

class RandomGameCreator : public GameCreator
{
public:
    HeroBuilder *get_hero_builder()
    {

        return new RandomHeroBuilder();
    }
};


#endif //RPG_RANDOMGAMECREATOR_H
