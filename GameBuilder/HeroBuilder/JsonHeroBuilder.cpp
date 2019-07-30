#include <iostream>
#include <fstream>
#include "JsonHeroBuilder.h"
#include "IncreaseChanceOfDobge.h"
#include "IncreaseResistanceToDamage.h"
#include "IncreaseCriticalHitChanceDefense.h"
#include "IncreaseReflectionOfDamage.h"
#include "IncreaseCharacteristicDefense.h"

using nlohmann::json;

JsonHeroBuilder::JsonHeroBuilder(const std::string &file_path)
        : m_file_path(file_path),
          m_config(json::parse(read_json_file()))
{
}

std::unique_ptr <Defense> JsonHeroBuilder::decorate_defence(numDefenseDecorator decorator_num, std::unique_ptr <Defense> &decorated_obj)
{
    std::unique_ptr <Defense> decorator;
    switch (decorator_num)
    {
        case numDefenseDecorator::increase_characteristic:
            decorator.reset(new IncreaseCharacteristicDefense(decorated_obj,
                                                              m_config["armor_effects"]["increase_characteristic"]["points_to_increase"].get<uint8_t>(),
                                                              m_config["armor_effects"]["increase_characteristic"]["characteristic_type"].get<std::string>()));
            break;

        case numDefenseDecorator::increase_resists_to_damage:
            decorator.reset(new IncreaseResistanceToDamage(decorated_obj,
                                                           m_config["armor_effects"]["increase_resists_to_damage"]["resist_points"].get<uint8_t>(),
                                                           m_config["armor_effects"]["increase_resists_to_damage"]["damage_type"].get<types>()
            ));

            break;
        case numDefenseDecorator::increase_reflection_to_damage:
            decorator.reset(new IncreaseReflectionOfDamage(decorated_obj,
                                                           m_config["armor_effects"]["increase_reflection_to_damage"]["reflection_points"].get<uint8_t>(),
                                                           m_config["armor_effects"]["increase_reflection_to_damage"]["damage_type"].get<types>()
            ));

            break;

        case numDefenseDecorator::increase_chance_of_critical_hit:
            decorator.reset(new IncreaseCriticalHitChanceDefense(decorated_obj,
                                                                 m_config["armor_effects"]["increase_chance_of_critical_hit"]["points_to_increase"].get<uint8_t>()
            ));
            break;

        case numDefenseDecorator::increase_chance_of_dodge:

            decorator.reset(new IncreaseChanceOfDobge(decorated_obj,
                                                      m_config["armor_effects"]["increase_chance_of_dodge"]["points_to_increase"].get<uint8_t>()));
            break;


        default:
            throw std::runtime_error("Unknown type of defense decorator");
    }
    return decorator;
}

std::unique_ptr <Defense> JsonHeroBuilder::build_magic_amulet(const std::string &hero)
{
    auto amulet_info = m_config[hero]["outfit"]["magic_attributes"]["amulet"];
    std::unique_ptr <Defense> amulet(new MagicDefense("amulet",
                                                      amulet_info["type_of_resistance"].get<types>(),
                                                      amulet_info["type_of_resistance"].get<uint8_t>()));
    for (json::iterator it = amulet_info["additional_effects"].begin();
         it != amulet_info["additional_effects"].end(); ++it)
    {
        amulet = decorate_defence((*it).get<numDefenseDecorator>(), amulet);
    }
    return amulet;
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

PhysicalDefense JsonHeroBuilder::build_head_protection(const std::string &hero)
{

}

PhysicalDefense JsonHeroBuilder::build_torso_protection(const std::string &hero)
{

}

PhysicalDefense JsonHeroBuilder::build_legs_protection(const std::string &hero)
{

}

PhysicalDefense JsonHeroBuilder::build_boots_protection(const std::string &hero)
{

}

PhysicalDefense JsonHeroBuilder::build_gloves_protection(const std::string &hero)
{

}

PhysicalDefense JsonHeroBuilder::build_shield(const std::string &hero)
{

}

std::vector <Weapon> JsonHeroBuilder::build_weapon(const std::string &hero)
{

}



JsonHeroBuilder::~JsonHeroBuilder()
{
    
}
