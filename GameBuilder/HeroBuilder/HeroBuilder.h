#pragma once
#ifndef RPG_HEROBUILDER_H
#define RPG_HEROBUILDER_H

#include <vector>
#include <memory>
#include "Character.h"
#include "MagicWeapon.h"
#include "PhysicalWeapon.h"
#include "MagicDefense.h"
#include "PhysicalDefense.h"

class HeroBuilder
{
public:
    Character build_first_hero();

    Character build_second_hero();

    virtual ~HeroBuilder() = 0;

public:
    Character build_hero(const std::string &hero);

    Outfit build_hero_outfit(const std::string &hero);

    Characterization build_hero_personality(const std::string &hero);

    virtual std::vector <std::unique_ptr<Defense>> build_magic_defenses(const std::string &hero) = 0;

    virtual std::vector <std::unique_ptr<Defense>> build_physical_defenses(const std::string &hero) = 0;

    virtual std::unique_ptr <Defense> build_shield(const std::string &hero) = 0;

    virtual std::vector <std::unique_ptr<Weapon>> build_weapon(const std::string &hero) = 0;
};

enum class numDefenseDecorator
{
    increase_characteristic = 1,
    increase_resists_to_damage = 2,
    increase_reflection_to_damage,
    increase_chance_of_critical_hit,
    increase_chance_of_dodge,
};

enum class numWeaponDecorator
{
    additional_damage = 1,
    increase_characteristic = 2,
    increase_chance_of_critical_hit,
    increase_damage_modifier,
    stunning,
    breaking,
    piercing,
    damn,
};
#endif //RPG_HEROBUILDER_H
