#include "HeroBuilder.h"

std::vector<Character> HeroBuilder::get_heroes()
{
    return std::vector<Character> { build_hero("first"), build_hero("second")};
}

Character HeroBuilder::build_hero(const std::string& hero_name)
{

}
