#ifndef RPG_JSONHEROBUILDER_H
#define RPG_JSONHEROBUILDER_H
#include <iostream>
#include "HeroBuilder.h"
class JsonHeroBuilder : public HeroBuilder
{
public:
    JsonHeroBuilder(const std::string & file_path)
    {

    }
};


#endif //RPG_JSONHEROBUILDER_H
