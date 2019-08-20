#include "HeroBuilder.h"

Character HeroBuilder::build_first_hero()
{
    return build_hero("first_hero");
}

Character HeroBuilder::build_second_hero()
{
    return build_hero("second_hero");
}

Character HeroBuilder::build_hero(const std::string &hero)
{
    Outfit outfit(build_hero_outfit(hero));
    CharacterizationObservable characterization(build_hero_personality(hero));
    return Character(outfit, characterization, hero);
}

Outfit HeroBuilder::build_hero_outfit(const std::string &hero)
{
    Outfit outfit;

    std::vector <std::unique_ptr<Defense>> magic_defenses(build_magic_defenses(hero));
    if (magic_defenses.size() != 3)
    {
        throw std::logic_error("Quantity of magic defenses must be equal 3 : 2 rings and 1 amulet");
    }
    for (auto &defense : magic_defenses)
    {
        outfit.add_defense(defense);
    }

    std::vector <std::unique_ptr<Defense>> physical_defenses(build_physical_defenses(hero));
    if (physical_defenses.size() != 5)
    {
        throw std::logic_error("Quantity of physical defenses must be equal 5 : "
                               "head"
                               "torso"
                               "legs"
                               "gloves"
                               "boots");
    }
    for (auto &defense : physical_defenses)
    {
        outfit.add_defense(defense);
    }

    std::unique_ptr <Defense> shield(build_shield(hero));
    if (shield)
    {
        outfit.add_defense(shield);
    }

    std::vector <std::unique_ptr<Weapon>> weapons(build_weapon(hero));
    if (weapons.size() > 2)
    {
        throw std::logic_error("Quantity of weapons cannot be greater than 2 : ");
    }
    for (auto &weapon : weapons)
    {
        outfit.add_weapon(weapon);
    }
    return outfit;
}

HeroBuilder::~HeroBuilder()
{

}
