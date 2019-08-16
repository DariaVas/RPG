#include "Outfit.h"

Outfit::Outfit(Outfit&& o):
    m_defenses(std::move(o.m_defenses)),
    m_weapons(std::move(o.m_weapons))
{

}

Outfit::Outfit()
{

}

Outfit::Outfit(std::vector<std::unique_ptr<Defense> > &defenses, std::vector<std::unique_ptr<Weapon> > &weapons)
    : m_defenses(std::move(defenses)),
      m_weapons(std::move(weapons))
{

}

void Outfit::add_defense(std::unique_ptr<Defense>& defense)
{
    m_defenses.emplace_back(std::move(defense));
}

void Outfit::add_weapon(std::unique_ptr<Weapon>& weapon)
{
    m_weapons.emplace_back(std::move(weapon));
}
