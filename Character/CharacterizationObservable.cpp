#include <plog/Log.h>
#include "CharacterizationObservable.h"

const size_t g_characteristic_upper_bound = 1000;

CharacterizationObservable::CharacterizationObservable() :
        m_characterizations{
                {characteristic::strength,     0},
                {characteristic::sleight,      0},
                {characteristic::intelligence, 0},
                {characteristic::physique,     0},
                {characteristic::luck,         0},
                {characteristic::initiative,   0}
        }
{}

CharacterizationObservable::CharacterizationObservable(size_t strength, size_t sleight, size_t intelligence,
                                                       size_t physique, size_t luck, size_t initiative) :
        m_characterizations
                {
                        {characteristic::strength,     strength},
                        {characteristic::sleight,      sleight},
                        {characteristic::intelligence, intelligence},
                        {characteristic::physique,     physique},
                        {characteristic::luck,         luck},
                        {characteristic::initiative,   initiative}
                }
{
    for (auto &ch : m_characterizations)
    {
        check_characterization_upper_bound(ch.first);
    }
}

size_t CharacterizationObservable::get_characteristic(characteristic feature)
{
    auto f = m_characterizations.find(feature);
    if (f == m_characterizations.end())
    {
        throw std::runtime_error("Cannot find feature");
    }
    return f->second;
}

void CharacterizationObservable::set_characteristic(characteristic feature, size_t feature_value)
{
    auto f = m_characterizations.find(feature);
    if (f == m_characterizations.end())
    {
        throw std::runtime_error("Cannot find feature");
    }
    size_t value_before = f->second;
    f->second = feature_value;

    check_characterization_upper_bound(feature);

    notify_observers(feature, f->second - value_before);
}

void CharacterizationObservable::add_observer(Observer *o)
{
    m_observers.push_back(o);
}

void CharacterizationObservable::remove_observer(Observer *o)
{
    m_observers.remove(o);
}

void CharacterizationObservable::notify_observers(characteristic changed_feature, int changed_delta)
{
    for (Observer *o: m_observers)
    {
        o->handle_event(changed_feature, changed_delta);
    }
    LOGI << "CharacterizationObservable notified all observers about changed feature ";
}

void CharacterizationObservable::check_characterization_upper_bound(characteristic type)
{
    if (m_characterizations[type] > g_characteristic_upper_bound)
    {
        m_characterizations[type] = g_characteristic_upper_bound;
    }
}

