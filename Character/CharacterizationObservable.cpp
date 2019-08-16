#include "CharacterizationObservable.h"

CharacterizationObservable::CharacterizationObservable() :
        m_characterizations{
                {Characteristic::strength,     0},
                {Characteristic::sleight,      0},
                {Characteristic::intelligence, 0},
                {Characteristic::physique,     0},
                {Characteristic::luck,         0},
                {Characteristic::initiative,   0}
        }
{}

CharacterizationObservable::CharacterizationObservable(size_t strength, size_t sleight, size_t intelligence,
                           size_t physique, size_t luck, size_t initiative) :
m_characterizations
{
        {Characteristic::strength,     strength},
        {Characteristic::sleight,      sleight},
        {Characteristic::intelligence, intelligence},
        {Characteristic::physique,     physique},
        {Characteristic::luck,         luck},
        {Characteristic::initiative,   initiative}
}
{

}
size_t CharacterizationObservable::get_characteristic(std::string feature_name)
{
    auto feature = m_characterizations.find(feature_name);
    if (feature == m_characterizations.end())
    {
        throw std::runtime_error("Cannot find feature");
    }
    return feature->second;
}

void CharacterizationObservable::set_characteristic(std::string feature_name, size_t feature_value)
{
    auto feature = m_characterizations.find(feature_name);
    if (feature == m_characterizations.end())
    {
        throw std::runtime_error("Cannot find feature");
    }

    feature->second = feature_value;

    notify_observers();
}

void CharacterizationObservable::add_observer(Observer* o)
{
    m_observers.push_back(o);
}

void CharacterizationObservable::remove_observer(Observer* o)
{
    m_observers.remove(o);
}

void CharacterizationObservable::notify_observers()
{
    for (Observer* o: m_observers)
    {
        o->handle_event(this);
    }
}
