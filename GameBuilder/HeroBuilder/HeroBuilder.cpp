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
    Outfit outfit(build_hero_outfit);
    Characterization characterization(build_hero_personality);
    return Character(outfit, characterization);
}

Outfit HeroBuilder::build_hero_otfit(const std::string &hero)
{
//    std::vector < Defense &> defense_things;
//    std::vector <MagicDefense> rings(build_magic_rings(name));
//    if (rings.size() > 2)
//    {
//        throw std::logic_error("Count of magic rings cannot be more than 2");
//    }
//    std::move(std::make_move_iterator(rings.begin()),
//              std::make_move_iterator(rings.end()),
//              std::back_inserter(defense_things));

//    defense_things.push_back(build_magic_amulet(hero));
//    defense_things.push_back(build_head_protection(hero));
//    defense_things.push_back(build_torso_protection(hero));
//    defense_things.push_back(build_legs_protection(hero));
//    defense_things.push_back(build_gloves_protection(hero));
//    std::vector <Weapon> weapons(build_weapon(hero));
//    if (weapons.size() < 2)
//    {
//        // There is also slot for a shield
//        defense_things.push_back(build_shield(hero));
//    }
//    return Outfit(defense_things, weapons);

}

Characterization HeroBuilder::build_hero_personality(const std::string &hero)
{
    return Characterization;
}
