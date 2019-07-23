#ifndef OUTFIT_H
#define OUTFIT_H

#include "Weapon/magicweapon.h"
#include "Weapon/physicalweapon.h"
#include "Defense/magicdefense.h"
#include "Defense/physicaldefense.h"

class Outfit
{
public:
    Outfit(std::vector<Defense>&& defense_things, std::vector<Weapon>&& weapons);
private:
    std::vector<Defense> m_defenses;
    std::vector<Weapon> m_weapons;
};

#endif // OUTFIT_H
