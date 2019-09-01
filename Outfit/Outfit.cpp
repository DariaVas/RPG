#include <stdlib.h>
#include <time.h>
#include <plog/Log.h>
#include "Outfit.h"
#include "Utils.h"

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
    m_weight += defense->get_weight();
    m_defenses.emplace_back(std::move(defense));
}

void Outfit::add_weapon(std::unique_ptr <Weapon> &weapon)
{
    m_weight += weapon->get_weight();
    m_weapons.emplace_back(std::move(weapon));
}

std::vector <Damage> Outfit::generate_damages(Character *ch)
{
    std::vector <Damage> damages;
    for (auto &weapon : m_weapons)
    {
        damages.emplace_back(weapon->generate_damage(ch));
    }
    return damages;
}

void Outfit::apply_magic_effect(Character *ch)
{
    for (auto &thing : m_weapons)
    {
        thing->apply_effect(ch);
    }

    for (auto &thing : m_defenses)
    {
        thing->apply_effect(ch);
    }
}


void Outfit::apply_effect_after_attack(Character *ch)
{
    for (auto &weapon : m_weapons)
    {
        weapon->effect_after_attack(ch);
    }
}

void Outfit::break_random_thing(Character *ch, size_t value_to_break)
{
    bool is_broken_weapon = false;
    size_t thing_to_break = utils::rdtsc() % (m_weapons.size() + m_defenses.size());
    Thing *thing;
    if (thing_to_break >= m_weapons.size())
    {
        thing_to_break -= m_weapons.size();
        thing = m_defenses[thing_to_break].get();
    }
    else
    {
        thing = m_weapons[thing_to_break].get();
        is_broken_weapon = true;
    }
    thing->reduce_durability(value_to_break);
    if (thing->is_broken())
    {
        thing->discard_effect(ch);
        m_weight -= thing->get_weight();
        LOGI << "Thing " << thing->get_name() << " was broken, so all applied effects was discarded";
        if (is_broken_weapon)
        {
            m_weapons.erase(m_weapons.begin() + thing_to_break);
        }
        else
        {
            m_defenses.erase(m_defenses.begin() + thing_to_break);
        }
    }
}

size_t Outfit::get_outift_weight()
{
    return m_weight;
}

void Outfit::lost_thing(Character *ch)
{
    if(m_defenses.size())
    {
        m_defenses.back()->discard_effect(ch);
        m_defenses.pop_back();
    }
    else if(m_weapons.size())
    {
        m_weapons.back()->discard_effect(ch);
        m_weapons.pop_back();
    }
    else
    {
        LOGI << ch->get_hero_name() << " has lost all things";
    }
}
