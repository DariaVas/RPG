#pragma once
#ifndef RPG_RANDOMHEROBUILDER_H
#define RPG_RANDOMHEROBUILDER_H

#include "HeroBuilder.h"

class RandomHeroBuilder : public HeroBuilder
{
public:
    ~RandomHeroBuilder() = default;
private:
    CharacterizationObservable build_hero_personality(const std::string &hero) override;

    std::vector <std::unique_ptr<Defense>> build_magic_defenses(const std::string &hero) override;

    std::vector <std::unique_ptr<Defense>> build_physical_defenses(const std::string &hero) override;

    std::unique_ptr <Defense> build_shield(const std::string &hero) override;

    std::vector <std::unique_ptr<Weapon>> build_weapon(const std::string &hero) override;
};


#endif //RPG_RANDOMHEROBUILDER_H
