#ifndef RPG_JSONHEROBUILDER_H
#define RPG_JSONHEROBUILDER_H

#include <iostream>
#include "HeroBuilder.h"
#include "json.hpp"

class JsonHeroBuilder : public HeroBuilder
{
public:
    JsonHeroBuilder(const std::string &file_path);

    ~JsonHeroBuilder() override;

private:
    CharacterizationObservable build_hero_personality(const std::string &hero) override;

    std::list <std::unique_ptr<Defense>> build_magic_defenses(const std::string &hero) override;

    std::list <std::unique_ptr<Defense>> build_physical_defenses(const std::string &hero) override;

    std::unique_ptr <Defense> build_shield(const std::string &hero) override;

    std::list <std::unique_ptr<Weapon>> build_weapon(const std::string &hero) override;

    std::unique_ptr <Weapon> construct_weapon(const nlohmann::json &weapon_info);

    std::string read_json_file();

    void decorate_defence(numDefenseDecorator decorator_num, std::unique_ptr <Defense> &decorated_obj);

    void apply_defence_decorators(const nlohmann::json &thing_info, std::unique_ptr <Defense> &decorated_obj);

    void decorate_weapon(numWeaponDecorator decorator_num, std::unique_ptr <Weapon> &decorated_obj);

    void apply_weapon_decorators(const nlohmann::json &thing_info, std::unique_ptr <Weapon> &decorated_obj);

private:
    const std::string m_file_path;
    nlohmann::json m_config;
};


#endif //RPG_JSONHEROBUILDER_H
