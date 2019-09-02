#pragma once

#ifndef THING_H
#define THING_H

#include <cstdint>
#include <string>

class Character;

class Thing
{
public:
    Thing(const std::string &name);

    virtual void reduce_durability(unsigned int value);

    virtual bool is_broken();

    virtual void apply_effect(Character *character) = 0;

    virtual void discard_effect(Character *character) = 0;

    virtual const std::string& get_name();
    
    virtual size_t get_weight();
    
    virtual ~Thing() = default;

private:
    size_t m_durability;
    const std::string m_name;
    const size_t m_weight;
};

#endif // THING_H
