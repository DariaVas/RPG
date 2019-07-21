яыф#
ifndef СHARACTERIZATION_H
#define СHARACTERIZATION_H

#include <cstdint>
#include <map>

namespace Characteristic {

    const std::string strenght = "strenght";
    const std::string sleight = "sleight";
    const std::string intelligence = "intelligence";
    const std::string physique = "physique";
    const std::string luck = "luck";
    const std::string initiative = "initiative";

    struct Сharacterization
    {
    public:
        Сharacterization() :
                m_сharacterization{
                        {strenght,     0},
                        {sleight,      0},
                        {intelligence, 0},
                        {physique,     0},
                        {luck,         0},
                        {initiative,   0}
                }
        {}

        std::uint8_t get_characteristic(std::string feature_name)
        {
            auto feature = m_сharacterization.find(feature_name);
            if (feature == m_сharacterization.end())
            {
                throw std::runtime_error("Cannot find feature");
            }
            return feature->second;

        }

        void set_characteristic(std::string feature_name, std::uint8_t feature_value)
        {
            auto feature = m_сharacterization.find(feature_name);
            if (feature == m_сharacterization.end())
            {
                throw std::runtime_error("Cannot find feature");
            }
            feature->second = feature_value;
        }

    private:
        std::map <std::string, std::uint8_t> m_сharacterization;
    };
}


#endif // СHARACTERIZATION_H
