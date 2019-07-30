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
    std::vector <MagicDefense> build_magic_rings(const std::string &hero) override;

    std::unique_ptr <Defense>  build_magic_amulet(const std::string &hero) override;

    PhysicalDefense build_head_protection(const std::string &hero) override;

    PhysicalDefense build_torso_protection(const std::string &hero) override;

    PhysicalDefense build_legs_protection(const std::string &hero) override;

    PhysicalDefense build_boots_protection(const std::string &hero) override;

    PhysicalDefense build_gloves_protection(const std::string &hero) override;

    PhysicalDefense build_shield(const std::string &hero) override;

    std::vector <Weapon> build_weapon(const std::string &hero) override;

    std::string read_json_file();
    std::unique_ptr <Defense> decorate_defence(numDefenseDecorator decorator_num, std::unique_ptr <Defense> &decorated_obj);


private:
    const std::string m_file_path;
    nlohmann::json m_config;
};


#endif //RPG_JSONHEROBUILDER_H
