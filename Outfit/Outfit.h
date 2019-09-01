#pragma once
#ifndef OUTFIT_H
#define OUTFIT_H

#include <memory>
#include <list>
#include "Weapon.h"
#include "Defense.h"

struct choosen_thing
{
    bool is_defense;
    size_t index;
    bool broken;
};

class Outfit
{
public:
    Outfit(Outfit &&o);

    Outfit();

    Outfit(std::list <std::unique_ptr<Defense>> &defenses, std::list <std::unique_ptr<Weapon>> &weapons);

    void add_defense(std::unique_ptr <Defense> &defense);

    void add_weapon(std::unique_ptr <Weapon> &weapon);

    void apply_magic_effect(Character *ch);

    std::vector <Damage> generate_damages(Character *ch);

    void apply_effect_after_attack(Character *ch);

    void break_random_thing(Character *ch, size_t value_to_break);
    
    size_t get_outift_weight();

    void lost_thing(Character *ch);

    void break_hit_thing(Character *ch, size_t value_to_break);

    ~Outfit() = default;

private:
    void break_thing(Character *ch, choosen_thing& thing, size_t value_to_break);
private:
    std::list <std::unique_ptr<Defense>> m_defenses;
    std::list <std::unique_ptr<Weapon>> m_weapons;
    choosen_thing m_hit_thing;
};

#endif // OUTFIT_H
