#pragma once
#ifndef OUTFIT_H
#define OUTFIT_H
#include <memory>
#include "magicweapon.h"
#include "physicalweapon.h"
#include "magicdefense.h"
#include "physicaldefense.h"

class Outfit
{
public:
    Outfit(std::vector <std::unique_ptr<Defense>> &&defense_things, std::vector <std::unique_ptr<Weapon>> &&weapons)
    {

    }

private:
    std::vector <std::unique_ptr<Defense>> m_defenses;
    std::vector <std::unique_ptr<Weapon>> m_weapons;
};

#endif // OUTFIT_H
