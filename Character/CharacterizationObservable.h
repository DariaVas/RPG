#pragma once
#ifndef CHARACTERIZATION_H
#define CHARACTERIZATION_H

#include <cstdint>
#include <map>
#include <list>
#include "Observer.h"

namespace Characteristic {

    const std::string strength = "strength";
    const std::string sleight = "sleight";
    const std::string intelligence = "intelligence";
    const std::string physique = "physique";
    const std::string luck = "luck";
    const std::string initiative = "initiative";
}

class CharacterizationObservable
{
public:
    CharacterizationObservable();
    CharacterizationObservable(size_t strength, size_t sleight, size_t intelligence,
                               size_t physique, size_t luck, size_t initiative);
    void add_observer(Observer* o);
    void remove_observer(Observer* o);
    size_t get_characteristic(std::string feature_name);
    void set_characteristic(std::string feature_name, size_t feature_value);
private:
   void notify_observers();
private:
    std::map <std::string, size_t> m_characterizations;
    std::list<Observer*> m_observers;
};


#endif // CHARACTERIZATION_H
