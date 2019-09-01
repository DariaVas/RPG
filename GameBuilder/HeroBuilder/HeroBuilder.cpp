#include <plog/Log.h>
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
    LOGI << "Creating " << hero;
    Outfit outfit(build_hero_outfit(hero));
    CharacterizationObservable characterization(build_hero_personality(hero));
    return Character(outfit, characterization, hero);
}

Outfit HeroBuilder::build_hero_outfit(const std::string &hero)
{
    LOGI << "Building outfit for " << hero;

    Outfit outfit;

    LOGI << "Buildig magic defenses";

    std::list <std::unique_ptr<Defense>> magic_defenses(build_magic_defenses(hero));
    if (magic_defenses.size() != 3)
    {
        throw std::logic_error("Quantity of magic defenses must be equal 3 : 2 rings and 1 amulet");
    }
    for (auto &defense : magic_defenses)
    {
        outfit.add_defense(defense);
    }

    std::list <std::unique_ptr<Defense>> physical_defenses(build_physical_defenses(hero));
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

    std::list <std::unique_ptr<Weapon>> weapons(build_weapon(hero));
    if (weapons.size() > 2 || (shield && weapons.size() == 2))
    {
        throw std::logic_error("Quantity of weapons cannot be greater than 2, "
                               "also hero can hold only 1 weapon if he has shield");
    }
    for (auto &weapon : weapons)
    {
        outfit.add_weapon(weapon);
    }
    LOGI << "Outfit for " << hero << " was built. ";
    return outfit;
}

HeroBuilder::~HeroBuilder()
{

}
