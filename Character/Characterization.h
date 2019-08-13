#pragma once
#ifndef CHARACTERIZATION_H
#define CHARACTERIZATION_H

#include <cstdint>
#include <map>

namespace Characteristic {

    const std::string strength = "strength";
    const std::string sleight = "sleight";
    const std::string intelligence = "intelligence";
    const std::string physique = "physique";
    const std::string luck = "luck";
    const std::string initiative = "initiative";
}
struct Characterization
{
public:
    Characterization() :
            m_characterization{
                    {Characteristic::strength,     0},
                    {Characteristic::sleight,      0},
                    {Characteristic::intelligence, 0},
                    {Characteristic::physique,     0},
                    {Characteristic::luck,         0},
                    {Characteristic::initiative,   0}
            }
    {}

    size_t get_characteristic(std::string feature_name)
    {
        auto feature = m_characterization.find(feature_name);
        if (feature == m_characterization.end())
        {
            throw std::runtime_error("Cannot find feature");
        }
        return feature->second;

    }

    void set_characteristic(std::string feature_name, size_t feature_value)
    {
        auto feature = m_characterization.find(feature_name);
        if (feature == m_characterization.end())
        {
            throw std::runtime_error("Cannot find feature");
        }
        feature->second = feature_value;
    }

private:
    std::map <std::string, size_t> m_characterization;
};


#endif // CHARACTERIZATION_H
