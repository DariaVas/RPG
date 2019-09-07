#include <stdlib.h>
#include <time.h>
#include <plog/Log.h>
#include "Outfit.h"
#include "Character.h"
#include "Utils.h"

Outfit::Outfit(Outfit &&o) :
        m_defenses(std::move(o.m_defenses)),
        m_weapons(std::move(o.m_weapons))
{

}

Outfit::Outfit()
{

}

Outfit::Outfit(std::list <std::unique_ptr<Defense>> &defenses, std::list <std::unique_ptr<Weapon>> &weapons)
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

std::vector <Damage> Outfit::generate_damages(Character *ch)
{
    std::vector <Damage> damages;
    for (auto &weapon : m_weapons)
    {
        std::vector<Damage> d (std::move(weapon->generate_damage(ch)));
        damages.insert(
            damages.end(),
            std::make_move_iterator(d.begin()),
            std::make_move_iterator(d.end())
          );
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
    if(m_weapons.empty()&& m_defenses.empty())
    {
        LOGW<<"There is no things to be broken";
        return;
    }
    size_t thing_to_break = utils::rdtsc() % (m_weapons.size() + m_defenses.size());
    if (thing_to_break >= m_weapons.size())
    {
        thing_to_break-=m_weapons.size();
        std::list<std::unique_ptr<Defense>>::iterator it = std::next(m_defenses.begin(), thing_to_break);

        (*it)->reduce_durability(value_to_break);
        if((*it)->is_broken())
        {
            auto thing = std::move(*it);
            m_defenses.erase(it);
            thing->discard_effect(ch);
            LOGI << "Thing " << thing->get_name() << " was broken, so all applied effects was discarded";
        }
    }
    else
    {
        std::list<std::unique_ptr<Weapon>>::iterator it = std::next(m_weapons.begin(), thing_to_break);
        (*it)->reduce_durability(value_to_break);
        if((*it)->is_broken())
        {
            auto thing = std::move(*it);
            m_weapons.erase(it);
            thing->discard_effect(ch);
            LOGI << "Thing " << thing->get_name() << " was broken, so all applied effects was discarded";
        }
    }
}

size_t Outfit::get_outift_weight()
{
    size_t weight = 0;
    for (const auto & thing : m_defenses)
    {
        weight += thing->get_weight();
    }
    for (const auto & thing : m_weapons)
    {
        weight += thing->get_weight();
    }
    return weight;
}

void Outfit::lost_thing(Character *ch)
{
    if(m_defenses.size())
    {
        auto defense = std::move(m_defenses.back());
        m_defenses.pop_back();
        defense->discard_effect(ch);
        LOGI<<ch->get_hero_name() << " lost " << defense->get_name();
    }
    else if(m_weapons.size())
    {
        auto weapon = std::move(m_weapons.back());
        m_weapons.pop_back();
        weapon->discard_effect(ch);
        LOGI<<ch->get_hero_name() << " lost " << weapon->get_name();
    }
    else
    {
        LOGI << ch->get_hero_name() << " has lost all things";
    }
}
