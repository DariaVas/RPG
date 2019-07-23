#ifndef RPG_HEROBUILDER_H
#define RPG_HEROBUILDER_H
#include <vector>
#include "Character.h"
#include "Weapon/magicweapon.h"
#include "Weapon/physicalweapon.h"
#include "Defense/magicdefense.h"
#include "Defense/physicaldefense.h"

class HeroBuilder
{
public:
    Character build_first_hero();
    Character build_second_hero();
private:
    Character build_hero(const std::string& hero);
    Outfit build_hero_outfit(const std::string& hero);
    Сharacterization build_hero_personality(const std::string& hero);
    virtual std::vector<MagicDefense>  build_magic_rings(const std::string& hero) = 0;
    virtual MagicDefense  build_magic_amulet(const std::string& hero)= 0;
    virtual PhysicalDefense  build_head_protection(const std::string& hero)= 0;
    virtual PhysicalDefense  build_torso_protection(const std::string& hero)= 0;
    virtual PhysicalDefense  build_legs_protection(const std::string& hero)= 0;
    virtual PhysicalDefense  build_boots_protection(const std::string& hero)= 0;
    virtual PhysicalDefense  build_gloves_protection(const std::string& hero)= 0;
    virtual PhysicalDefense  build_shield(const std::string& hero)= 0;
    virtual std::vector<Weapon>  build_weapon(const std::string& hero)= 0;
};


#endif //RPG_HEROBUILDER_H
