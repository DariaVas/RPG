#pragma once
#ifndef OUTFIT_H
#define OUTFIT_H

#include <memory>
#include <vector>
#include "Weapon.h"
#include "Defense.h"

class Outfit
{
public:
    Outfit(Outfit &&o);

    Outfit();

    Outfit(std::vector <std::unique_ptr<Defense>> &defenses, std::vector <std::unique_ptr<Weapon>> &weapons);

    void add_defense(std::unique_ptr <Defense> &defense);

    void add_weapon(std::unique_ptr <Weapon> &weapon);

    void apply_magic_effect(Character* ch);

    std::vector<Damage> generate_damages(Character* ch);

    ~Outfit() = default;

private:
    std::vector <std::unique_ptr<Defense>> m_defenses;
    std::vector <std::unique_ptr<Weapon>> m_weapons;
};

#endif // OUTFIT_H
