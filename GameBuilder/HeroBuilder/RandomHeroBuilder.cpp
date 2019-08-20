#include "RandomHeroBuilder.h"

CharacterizationObservable RandomHeroBuilder::build_hero_personality(const std::string &hero)
{
    throw std::runtime_error ("Not implemented error");
}

std::vector <std::unique_ptr<Defense>> RandomHeroBuilder::build_magic_defenses(const std::string &hero)
{
    throw std::runtime_error ("Not implemented error");
}

std::vector <std::unique_ptr<Defense>> RandomHeroBuilder::build_physical_defenses(const std::string &hero)
{
    throw std::runtime_error ("Not implemented error");
}

std::unique_ptr <Defense> RandomHeroBuilder::build_shield(const std::string &hero)
{
    throw std::runtime_error ("Not implemented error");
}

std::vector <std::unique_ptr<Weapon>> RandomHeroBuilder::build_weapon(const std::string &hero)
{
    throw std::runtime_error ("Not implemented error");
}
