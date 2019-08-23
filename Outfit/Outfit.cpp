#include "Outfit.h"
#include <stdlib.h>
#include <time.h>

Outfit::Outfit(Outfit &&o) :
        m_defenses(std::move(o.m_defenses)),
        m_weapons(std::move(o.m_weapons))
{

}

Outfit::Outfit()
{

}

Outfit::Outfit(std::vector <std::unique_ptr<Defense>> &defenses, std::vector <std::unique_ptr<Weapon>> &weapons)
        : m_defenses(std::move(defenses)),
          m_weapons(std::move(weapons))
{

}

void Outfit::add_defense(std::unique_ptr <Defense> &defense)
{
    m_defenses.emplace_back(std::move(defense));
}

void Outfit::add_weapon(std::unique_ptr <Weapon> &weapon)
{
    m_weapons.emplace_back(std::move(weapon));
}

std::vector<Damage> Outfit::generate_damages(Character* ch)
{
    std::vector<Damage> damages;
    for(auto& weapon : m_weapons)
    {
        damages.emplace_back(weapon->generate_damage(ch));
    }
    return damages;
}

void Outfit::apply_magic_effect(Character *ch)
{
    for(auto& thing : m_weapons)
    {
        thing->apply_effect(ch);
    }

    for(auto& thing : m_defenses)
    {
        thing->apply_effect(ch);
    }
}


void Outfit::apply_effect_after_attack(Character* ch)
{
    for(auto& weapon : m_weapons)
    {
        weapon->effect_after_attack(ch);
    }
}

void Outfit::break_random_thing(size_t value_to_break)
{
    srand (time(NULL));
    int thing_to_break = rand() % (m_weapons.size() + m_defenses.size());
    if(thing_to_break >= m_weapons.size())
    {
        thing_to_break -= m_weapons.size();
        m_defenses[thing_to_break]->reduce_durability(value_to_break);
        if(m_defenses[thing_to_break]->is_broken())
        {
            m_defenses.erase(m_defenses.begin() + thing_to_break);
        }
    }
    else
    {
        m_weapons[thing_to_break]->reduce_durability(value_to_break);
        if(m_weapons[thing_to_break]->is_broken())
        {
            m_weapons.erase(m_weapons.begin() + thing_to_break);
        }
    }
}

