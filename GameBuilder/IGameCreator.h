#pragma once
#ifndef RPG_IGAMECREATOR_H
#define RPG_IGAMECREATOR_H

#include "HeroBuilder.h"

class IGameCreator
{
public:
    virtual HeroBuilder *get_hero_builder() = 0;

    virtual ~IGameCreator() = default;
};


#endif //RPG_IGAMECREATOR_H
