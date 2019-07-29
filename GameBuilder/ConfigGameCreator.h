#pragma once
#ifndef RPG_CONFIGGAMECREATOR_H
#define RPG_CONFIGGAMECREATOR_H

#include <iostream>
#include "GameCreator.h"
#include "JsonHeroBuilder.h"

class ConfigGameCreator : public GameCreator
{
public:
    HeroBuilder *get_hero_builder()
    {
        std::cout << "Please, enter the path to json config: " << std::endl;
        std::string path;
        std::cin >> path;
        return new JsonHeroBuilder(path);
    }

};


#endif //RPG_CONFIGGAMECREATOR_H
