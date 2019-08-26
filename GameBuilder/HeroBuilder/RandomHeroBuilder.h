#pragma once
#ifndef RPG_RANDOMHEROBUILDER_H
#define RPG_RANDOMHEROBUILDER_H

#include "HeroBuilder.h"

class RandomHeroBuilder : public HeroBuilder
{
public:
    RandomHeroBuilder();
    ~RandomHeroBuilder()=default;

private:
    CharacterizationObservable build_hero_personality(const std::string &hero) override;

    std::vector <std::unique_ptr<Defense>> build_magic_defenses(const std::string &hero) override;

    std::vector <std::unique_ptr<Defense>> build_physical_defenses(const std::string &hero) override;

    std::unique_ptr <Defense> build_shield(const std::string &hero) override;

    std::vector <std::unique_ptr<Weapon>> build_weapon(const std::string &hero) override;

    size_t generate_random_value(size_t upper_bound);

    damage_types get_random_magic_type();

    damage_types get_random_damage_type();

    void decorate_defence(numDefenseDecorator decorator_num, std::unique_ptr <Defense> &decorated_obj);

    void apply_defence_decorators(std::unique_ptr <Defense> &decorated_obj);

    characteristic get_random_characteristic();

    void apply_weapon_decorators(std::unique_ptr <Weapon> &decorated_obj);

    void decorate_weapon(numWeaponDecorator decorator_num, std::unique_ptr <Weapon> &decorated_obj);

    std::unique_ptr <Weapon> construct_weapon(const std::string& weapon_name, holding_type hold_type);
private:
    bool m_weapon_and_shield_chosen;
};


#endif //RPG_RANDOMHEROBUILDER_H
