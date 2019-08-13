#pragma once
#ifndef RPG_HEROBUILDER_H
#define RPG_HEROBUILDER_H

#include <vector>
#include <memory>
#include "Character.h"
#include "magicweapon.h"
#include "physicalweapon.h"
#include "magicdefense.h"
#include "physicaldefense.h"

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

    virtual std::vector <MagicDefense> build_magic_rings(const std::string &hero) = 0;

    virtual std::unique_ptr <Defense> build_magic_amulet(const std::string &hero) = 0;

    virtual PhysicalDefense build_head_protection(const std::string &hero) = 0;

    virtual PhysicalDefense build_torso_protection(const std::string &hero) = 0;

    virtual PhysicalDefense build_legs_protection(const std::string &hero) = 0;

    virtual PhysicalDefense build_boots_protection(const std::string &hero) = 0;

    virtual PhysicalDefense build_gloves_protection(const std::string &hero) = 0;

    virtual PhysicalDefense build_shield(const std::string &hero) = 0;

    virtual std::vector <Weapon> build_weapon(const std::string &hero) = 0;
};

enum numDefenseDecorator
{
    increase_characteristic = 1,
    increase_resists_to_damage = 2,
    increase_reflection_to_damage,
    increase_chance_of_critical_hit,
    increase_chance_of_dodge,
};
#endif //RPG_HEROBUILDER_H
