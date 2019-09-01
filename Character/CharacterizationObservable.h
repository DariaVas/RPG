#pragma once
#ifndef CHARACTERIZATION_H
#define CHARACTERIZATION_H

#include <cstdint>
#include <map>
#include <list>
#include "Observer.h"

enum class characteristic
{
    strength = 1,
    sleight = 2,
    intelligence,
    physique,
    luck,
    initiative,
};

extern const size_t
        g_characteristic_upper_bound;

class CharacterizationObservable
{
public:
    CharacterizationObservable();

    CharacterizationObservable(size_t strength, size_t sleight, size_t intelligence,
                               size_t physique, size_t luck, size_t initiative);

    void add_observer(Observer *o);

    void remove_observer(Observer *o);

    size_t get_characteristic(characteristic feature);

    void increase_characteristic(characteristic feature, size_t feature_value);

    void decrease_characteristic(characteristic feature, size_t feature_value);

private:
    void notify_observers(characteristic changed_feature, int changed_delta);

    void check_characterization_upper_bound(characteristic type);

private:
    std::map <characteristic, size_t> m_characterizations;
    std::list<Observer *> m_observers;
};


#endif // CHARACTERIZATION_H
