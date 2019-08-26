#include "RandomHeroBuilder.h"
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
#include "Utils.h"

RandomHeroBuilder::RandomHeroBuilder()
        : m_weapon_and_shield_chosen(static_cast<bool> (utils::rdtsc() % 2))
{

}

CharacterizationObservable RandomHeroBuilder::build_hero_personality(const std::string &hero)
{
    return CharacterizationObservable(generate_random_value(g_characteristic_upper_bound),
                                      generate_random_value(g_characteristic_upper_bound),
                                      generate_random_value(g_characteristic_upper_bound),
                                      generate_random_value(g_characteristic_upper_bound),
                                      generate_random_value(g_characteristic_upper_bound),
                                      generate_random_value(g_characteristic_upper_bound));
}

std::vector <std::unique_ptr<Defense>> RandomHeroBuilder::build_magic_defenses(const std::string &hero)
{
    const std::string magic_things_name[] = {"ring1", "ring2", "amulet"};
    std::vector <std::unique_ptr<Defense>> things;
    for (const auto &name : magic_things_name)
    {
        std::unique_ptr <Defense> thing(new MagicDefense(name,
                                                         get_random_magic_type(),
                                                         generate_random_value(g_parameter_upper_bound)));
        apply_defence_decorators(thing);
        things.emplace_back(std::move(thing));
    }
    return things;
}

std::vector <std::unique_ptr<Defense>> RandomHeroBuilder::build_physical_defenses(const std::string &hero)
{
    const std::string physical_things_name[] = {"head protection",
                                                "torso protection",
                                                "gloves",
                                                "legs protection",
                                                "boots"
    };
    std::vector <std::unique_ptr<Defense>> things;
    for (const auto &name : physical_things_name)
    {
        std::unique_ptr <Defense> thing(new PhysicalDefense(name,
                                                            damage_types::physical,
                                                            generate_random_value(g_parameter_upper_bound)));
        apply_defence_decorators(thing);
        things.emplace_back(std::move(thing));
    }
    return things;
}

std::unique_ptr <Defense> RandomHeroBuilder::build_shield(const std::string &hero)
{
    std::unique_ptr <Defense> shield;
    if (m_weapon_and_shield_chosen)
    {
        shield.reset(new PhysicalDefense("shield",
                                         damage_types::physical,
                                         generate_random_value(g_parameter_upper_bound)));
        apply_defence_decorators(shield);
    }
    return shield;
}

std::unique_ptr <Weapon> RandomHeroBuilder::construct_weapon(const std::string &weapon_name, holding_type hold_type)
{
    damage_types type = get_random_damage_type();
    if (type == damage_types::physical)
    {
        return std::unique_ptr<Weapon>(new PhysicalWeapon(weapon_name,
                                                          hold_type,
                                                          generate_random_value(g_parameter_upper_bound)));
    }
    else
    {
        return std::unique_ptr<Weapon>(new MagicWeapon(weapon_name,
                                                       hold_type,
                                                       type,
                                                       generate_random_value(g_parameter_upper_bound)));
    }
}

std::vector <std::unique_ptr<Weapon>> RandomHeroBuilder::build_weapon(const std::string &hero)
{
    std::vector <std::unique_ptr<Weapon>> weapons;

    if (m_weapon_and_shield_chosen)
    {
        std::unique_ptr <Weapon> weapon = construct_weapon("weapon", holding_type::one_handed);
        apply_weapon_decorators(weapon);
        weapons.emplace_back(std::move(weapon));
    }
    else
    {
        const size_t count_of_weapons = generate_random_value(2);
        if (count_of_weapons == 2)
        {
            std::unique_ptr <Weapon> weapon1 = construct_weapon("weapon1", holding_type::one_handed);
            apply_weapon_decorators(weapon1);
            weapons.emplace_back(std::move(weapon1));

            std::unique_ptr <Weapon> weapon2 = construct_weapon("weapon2", holding_type::one_handed);
            apply_weapon_decorators(weapon2);
            weapons.emplace_back(std::move(weapon2));
        }
        else
        {
            std::unique_ptr <Weapon> weapon = construct_weapon("weapon",
                                                               static_cast<holding_type>(generate_random_value(
                                                                       holding_type::two_handed)));
            apply_weapon_decorators(weapon);
            weapons.emplace_back(std::move(weapon));
        }
    }
    return weapons;
}

size_t RandomHeroBuilder::generate_random_value(size_t upper_bound)
{
    auto value = utils::rdtsc() % upper_bound + 1;
    return value;
}

damage_types RandomHeroBuilder::get_random_magic_type()
{
    return static_cast<damage_types>((utils::rdtsc() % static_cast<int>(damage_types::electric)) + 2);
}


void RandomHeroBuilder::decorate_defence(numDefenseDecorator decorator_num, std::unique_ptr <Defense> &decorated_obj)
{
    std::unique_ptr <Defense> decorator;
    switch (decorator_num)
    {
        case numDefenseDecorator::increase_characteristic:
            decorator.reset(new IncreaseCharacteristicDefense(decorated_obj,
                                                              generate_random_value(g_characteristic_upper_bound),
                                                              get_random_characteristic()));
            break;

        case numDefenseDecorator::increase_resists_to_damage:
            decorator.reset(new IncreaseResistanceToDamage(decorated_obj,
                                                           generate_random_value(g_parameter_upper_bound),
                                                           get_random_damage_type()
            ));

            break;
        case numDefenseDecorator::increase_reflection_to_damage:
            decorator.reset(new IncreaseReflectionOfDamage(decorated_obj,
                                                           generate_random_value(g_parameter_upper_bound),
                                                           get_random_damage_type()
            ));

            break;

        case numDefenseDecorator::increase_chance_of_critical_hit:
            decorator.reset(new IncreaseCriticalHitChanceDefense(decorated_obj,
                                                                 generate_random_value(g_parameter_upper_bound)
            ));
            break;

        case numDefenseDecorator::increase_chance_of_dodge:

            decorator.reset(new IncreaseChanceOfDodge(decorated_obj,
                                                      generate_random_value(g_parameter_upper_bound)));
            break;


        default:
            throw std::runtime_error("Unknown damage_types of defense decorator");
    }
    decorated_obj = std::move(decorator);
}


characteristic RandomHeroBuilder::get_random_characteristic()
{
    return static_cast<characteristic>(generate_random_value(static_cast<int>(characteristic::initiative)));
}

damage_types RandomHeroBuilder::get_random_damage_type()
{
    return static_cast<damage_types>((utils::rdtsc() % static_cast<int>(damage_types::acid)) + 1);
}

void RandomHeroBuilder::apply_defence_decorators(std::unique_ptr <Defense> &decorated_obj)
{
    const size_t count_of_decarators =
            utils::rdtsc() % (static_cast<size_t>(numDefenseDecorator::increase_chance_of_dodge) + 1);
    for (size_t i = 0; i < count_of_decarators; ++i)
    {
        decorate_defence(static_cast<numDefenseDecorator>(generate_random_value(
                static_cast<size_t>(numDefenseDecorator::increase_chance_of_dodge))), decorated_obj);
    }
}

void RandomHeroBuilder::apply_weapon_decorators(std::unique_ptr <Weapon> &decorated_obj)
{
    const size_t count_of_decarators = utils::rdtsc() % (static_cast<size_t>(numWeaponDecorator::damn) + 1);
    for (size_t i = 0; i < count_of_decarators; ++i)
    {
        decorate_weapon(
                static_cast<numWeaponDecorator>(generate_random_value(static_cast<size_t>(numWeaponDecorator::damn))),
                decorated_obj);
    }
}

void RandomHeroBuilder::decorate_weapon(numWeaponDecorator decorator_num, std::unique_ptr <Weapon> &decorated_obj)
{
    std::unique_ptr <Weapon> decorator;

    switch (decorator_num)
    {
        case numWeaponDecorator::additional_damage:
            decorator.reset(
                    new AdditionalHit(decorated_obj, generate_random_value(g_parameter_upper_bound)));
            break;
        case numWeaponDecorator::increase_characteristic:
            decorator.reset(new IncreaseCharacteristicWeapon(decorated_obj,
                                                             generate_random_value(g_characteristic_upper_bound),
                                                             get_random_characteristic()));
            break;
        case numWeaponDecorator::increase_chance_of_critical_hit:
            decorator.reset(new IncreaseCriticalHitChanceWeapon(decorated_obj,
                                                                generate_random_value(g_parameter_upper_bound)));
            break;
        case numWeaponDecorator::increase_damage_modifier:
            decorator.reset(new IncreaseCriticalHitModifier(decorated_obj,
                                                            generate_random_value(g_parameter_upper_bound)));

            break;
        case numWeaponDecorator::stunning:
            decorator.reset(
                    new StunningWeapon(decorated_obj));
            break;
        case numWeaponDecorator::breaking:
            decorator.reset(
                    new BreakingWeapon(decorated_obj, generate_random_value(g_parameter_upper_bound)));

            break;
        case numWeaponDecorator::piercing:
            decorator.reset(
                    new PiercingWeapon(decorated_obj, generate_random_value(g_parameter_upper_bound)));

            break;
        case numWeaponDecorator::damn:
            decorator.reset(new DamnedWeapon(decorated_obj, generate_random_value(g_characteristic_upper_bound),
                                             get_random_characteristic()));

            break;
        default:
            throw std::runtime_error("Unknown damage_types of weapon decorator");
    }
    decorated_obj = std::move(decorator);

}
