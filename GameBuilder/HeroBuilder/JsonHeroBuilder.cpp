#include <iostream>
#include <fstream>
#include "JsonHeroBuilder.h"
#include "IncreaseChanceOfDodge.h"
#include "IncreaseResistanceToDamage.h"
#include "IncreaseCriticalHitChanceDefense.h"
#include "IncreaseReflectionOfDamage.h"
#include "IncreaseCharacteristicDefense.h"

#include "AdditionalHit.h"
#include "BreakingWeapon.h"
#include "DamnedWeapon.h"
#include "IncreaseCharacteristicWeapon.h"
#include "IncreaseCriticalHitChanceWeapon.h"
#include "IncreaseCriticalHitModifier.h"
#include "PiercingWeapon.h"
#include "StunningWeapon.h"

using nlohmann::json;

JsonHeroBuilder::JsonHeroBuilder(const std::string &file_path)
        : m_file_path(file_path),
          m_config(json::parse(read_json_file()))
{
}

void JsonHeroBuilder::decorate_defence(numDefenseDecorator decorator_num, std::unique_ptr <Defense> &decorated_obj)
{
    std::unique_ptr <Defense> decorator;
    switch (decorator_num)
    {
        case numDefenseDecorator::increase_characteristic:
            decorator.reset(new IncreaseCharacteristicDefense(decorated_obj,
                                                              m_config["armor_effects"]["increase_characteristic"]["points_to_increase"].get<size_t>(),
                                                              m_config["armor_effects"]["increase_characteristic"]["characteristic_type"].get<characteristic>()));
            break;

        case numDefenseDecorator::increase_resists_to_damage:
            decorator.reset(new IncreaseResistanceToDamage(decorated_obj,
                                                           m_config["armor_effects"]["increase_resists_to_damage"]["resist_points"].get<size_t>(),
                                                           m_config["armor_effects"]["increase_resists_to_damage"]["damage_type"].get<damage_types>()
            ));

            break;
        case numDefenseDecorator::increase_reflection_to_damage:
            decorator.reset(new IncreaseReflectionOfDamage(decorated_obj,
                                                           m_config["armor_effects"]["increase_reflection_to_damage"]["reflection_points"].get<size_t>(),
                                                           m_config["armor_effects"]["increase_reflection_to_damage"]["damage_type"].get<damage_types>()
            ));

            break;

        case numDefenseDecorator::increase_chance_of_critical_hit:
            decorator.reset(new IncreaseCriticalHitChanceDefense(decorated_obj,
                                                                 m_config["armor_effects"]["increase_chance_of_critical_hit"]["points_to_increase"].get<size_t>()
            ));
            break;

        case numDefenseDecorator::increase_chance_of_dodge:

            decorator.reset(new IncreaseChanceOfDodge(decorated_obj,
                                                      m_config["armor_effects"]["increase_chance_of_dodge"]["points_to_increase"].get<size_t>()));
            break;


        default:
            throw std::runtime_error("Unknown damage_types of defense decorator");
    }
    decorated_obj = std::move(decorator);
}

void
JsonHeroBuilder::apply_defence_decorators(const nlohmann::json &thing_info, std::unique_ptr <Defense> &decorated_obj)
{
    for (json::const_iterator it = thing_info["additional_effects"].cbegin();
         it != thing_info["additional_effects"].cend(); ++it)
    {
        decorate_defence((*it).get<numDefenseDecorator>(), decorated_obj);
    }
}

void JsonHeroBuilder::decorate_weapon(numWeaponDecorator decorator_num, std::unique_ptr <Weapon> &decorated_obj)
{
    std::unique_ptr <Weapon> decorator;
    nlohmann::json &weapon_effects = m_config["weapon_effects"];

    switch (decorator_num)
    {
        case numWeaponDecorator::additional_damage:
            decorator.reset(
                    new AdditionalHit(decorated_obj, weapon_effects["additional_damage"]["damage"].get<size_t>()));
            break;
        case numWeaponDecorator::increase_characteristic:
            decorator.reset(new IncreaseCharacteristicWeapon(decorated_obj,
                                                             weapon_effects["increase_characteristic"]["points_to_increase"].get<size_t>(),
                                                             weapon_effects["increase_characteristic"]["characteristic_type"].get<characteristic>()));
            break;
        case numWeaponDecorator::increase_chance_of_critical_hit:
            decorator.reset(new IncreaseCriticalHitChanceWeapon(decorated_obj,
                                                                weapon_effects["increase_chance_of_critical_hit"]["points_to_increase"].get<size_t>()));
            break;
        case numWeaponDecorator::increase_damage_modifier:
            decorator.reset(new IncreaseCriticalHitModifier(decorated_obj,
                                                            weapon_effects["increase_damage_modifier"]["points_to_increase"].get<size_t>()));

            break;
        case numWeaponDecorator::stunning:
            decorator.reset(
                    new StunningWeapon(decorated_obj, weapon_effects["stunning"]["stunning_seconds"].get<size_t>()));
            break;
        case numWeaponDecorator::breaking:
            decorator.reset(
                    new BreakingWeapon(decorated_obj, weapon_effects["breaking"]["breaking_power"].get<size_t>()));

            break;
        case numWeaponDecorator::piercing:
            decorator.reset(
                    new PiercingWeapon(decorated_obj, weapon_effects["piercing"]["piercing_power"].get<size_t>()));

            break;
        case numWeaponDecorator::damn:
            decorator.reset(new DamnedWeapon(decorated_obj, weapon_effects["damn"]["points_to_decrease"].get<size_t>(),
                                             weapon_effects["damn"]["characteristic_type"].get<characteristic>()));

            break;
        default:
            throw std::runtime_error("Unknown damage_types of weapon decorator");
    }
    decorated_obj = std::move(decorator);

}

void JsonHeroBuilder::apply_weapon_decorators(const nlohmann::json &thing_info, std::unique_ptr <Weapon> &decorated_obj)
{
    for (json::const_iterator it = thing_info["additional_effects"].cbegin();
         it != thing_info["additional_effects"].cend(); ++it)
    {
        decorate_weapon((*it).get<numWeaponDecorator>(), decorated_obj);
    }
}

std::string JsonHeroBuilder::read_json_file()
{
    std::ifstream file;
    file.exceptions(std::ios::failbit | std::ios::badbit);
    file.open(m_file_path);
    std::string content;
    content.assign(std::istreambuf_iterator<char>(file),
                   std::istreambuf_iterator<char>());
    return content;
}

std::unique_ptr <Defense> JsonHeroBuilder::build_shield(const std::string &hero)
{
    std::unique_ptr <Defense> shield;
    if (m_config[hero]["outfit"]["defense_and_weapon_slots"]["choice"] == "weapon_shield")
    {
        auto shield_info = m_config[hero]["outfit"]["defense_and_weapon_slots"]["weapon_shield"]["shield"];
        shield.reset(new PhysicalDefense("shield",
                                         shield_info["type_of_resistance"].get<damage_types>(),
                                         shield_info["resistance"].get<size_t>()));
        apply_defence_decorators(shield_info, shield);
    }
    return shield;
}

std::unique_ptr <Weapon> JsonHeroBuilder::construct_weapon(const nlohmann::json &weapon_info)
{
    if (weapon_info["type_of_damage"] == damage_types::physical)
    {
        return std::unique_ptr<Weapon>(new PhysicalWeapon(weapon_info["name"],
                                                          weapon_info["arm_type"].get<holding_type>(),
                                                          weapon_info["damage"].get<size_t>()));
    } else
    {
        return std::unique_ptr<Weapon>(new MagicWeapon(weapon_info["name"],
                                                       weapon_info["arm_type"].get<holding_type>(),
                                                       weapon_info["type_of_damage"].get<damage_types>(),
                                                       weapon_info["damage"].get<size_t>()));
    }
}

std::vector <std::unique_ptr<Weapon>> JsonHeroBuilder::build_weapon(const std::string &hero)
{
    std::vector <std::unique_ptr<Weapon>> weapons;

    if (m_config[hero]["outfit"]["defense_and_weapon_slots"]["choice"] == "weapon_shield")
    {
        auto weapon_info = m_config[hero]["outfit"]["defense_and_weapon_slots"]["weapon_shield"]["weapon"];
        std::unique_ptr <Weapon> weapon(construct_weapon(weapon_info));
        apply_weapon_decorators(weapon_info, weapon);
        weapons.emplace_back(std::move(weapon));
    } else if (m_config[hero]["outfit"]["defense_and_weapon_slots"]["choice"] == "weapons_only")
    {
        auto weapons_info = m_config[hero]["outfit"]["defense_and_weapon_slots"]["weapons_only"];
        for (json::const_iterator it = weapons_info.cbegin();
             it != weapons_info.cend(); ++it)
        {
            const auto &weapon_info = *it;
            std::unique_ptr <Weapon> weapon;
            weapon = construct_weapon(weapon_info);
            apply_weapon_decorators(weapon_info, weapon);
            weapons.emplace_back(std::move(weapon));
        }
        if (weapons.size() > 2)
        {
            throw std::runtime_error("A Hero cannot have more than 2 weapons");
        } else if (weapons.size() == 2)
        {
            if (weapons[0]->get_hold_type() != holding_type::one_handed ||
                weapons[1]->get_hold_type() != holding_type::one_handed)
            {
                throw std::runtime_error("Logic error, if a hero has 2 weapons they must be one-handed");
            }
        }
    } else
    {
        throw std::runtime_error("Unknown choice of \"defense_and_weapon_slots\"");
    }
    return weapons;
}

std::vector <std::unique_ptr<Defense>> JsonHeroBuilder::build_magic_defenses(const std::string &hero)
{
    std::vector <std::unique_ptr<Defense>> magic_defenses;
    auto magic_defenses_info = m_config[hero]["outfit"]["magic_attributes"];
    for (json::const_iterator defense_info = magic_defenses_info.cbegin();
         defense_info != magic_defenses_info.cend(); ++defense_info)
    {
        std::unique_ptr <Defense> defense(new MagicDefense((*defense_info)["name"],
                                                           (*defense_info)["type_of_resistance"].get<damage_types>(),
                                                           (*defense_info)["resistance"].get<size_t>()));
        apply_defence_decorators((*defense_info), defense);
        magic_defenses.emplace_back(std::move(defense));
    }
    return magic_defenses;
}

std::vector <std::unique_ptr<Defense>> JsonHeroBuilder::build_physical_defenses(const std::string &hero)
{
    std::vector <std::unique_ptr<Defense>> physical_defenses;
    auto physical_defenses_info = m_config[hero]["outfit"]["armor"];
    for (json::const_iterator defense_info = physical_defenses_info.cbegin();
         defense_info != physical_defenses_info.cend(); ++defense_info)
    {
        std::unique_ptr <Defense> defense(new PhysicalDefense((*defense_info)["name"],
                                                              (*defense_info)["type_of_resistance"].get<damage_types>(),
                                                              (*defense_info)["resistance"].get<size_t>()));
        apply_defence_decorators((*defense_info), defense);
        physical_defenses.emplace_back(std::move(defense));
    }

    return physical_defenses;
}

CharacterizationObservable JsonHeroBuilder::build_hero_personality(const std::string &hero)
{
    auto characteristic = m_config[hero]["characteristic"];
    return CharacterizationObservable(characteristic["strength"].get<size_t>(),
                                      characteristic["sleight"].get<size_t>(),
                                      characteristic["intelligence"].get<size_t>(),
                                      characteristic["physique"].get<size_t>(), characteristic["luck"].get<size_t>(),
                                      characteristic["initiative"].get<size_t>());
}

JsonHeroBuilder::~JsonHeroBuilder()
{

}
