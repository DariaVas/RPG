#pragma once

#ifndef THING_H
#define THING_H

class Character;

class Thing
{
public:
    Thing(const std::string &name);

    virtual void reduce_durability(unsigned int value);

    bool is_broken();

    virtual void apply_effect(Character &character) = 0;

    virtual void discard_effect(Character &character) = 0;
    std::uint8_t get_durability();
    std::string get_name();
    virtual ~Thing() = default;

private:
    unsigned int m_durability;
    const std::string m_name;
};

#endif // THING_H
