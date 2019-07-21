#ifndef RPG_HEROBUILDER_H
#define RPG_HEROBUILDER_H
#include <vector>
#include "Character.h"

class HeroBuilder
{
public:
    std::vector<Character> get_heroes();
private:
    Character build_hero(const std::string& hero_name);
};


#endif //RPG_HEROBUILDER_H
