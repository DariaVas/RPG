#ifndef INCREASINGCHARACTERISTICDEFENSE_H
#define INCREASINGCHARACTERISTICDEFENSE_H

#include <iostream>
#include "DefenseDecorator.h"
#include "Character/Character.h"

class IncreasingCharacteristicDefense final : public DefenseDecorator
{
public:

    IncreasingCharacteristicDefense(Defense &decorator, std::uint8_t value, std::string characteristic) :
            DefenseDecorator(decorator),
            m_characteristic_name(characteristic),
            m_value(value)
    {

    }

    void apply_effect(Character &character) override
    {
        std::uint8_t ch_value = character.get_characteristic(m_characteristic_name);
        character.set_characteristic(m_characteristic_name, ch_value + m_value);
        std::cout << "Apply magic effect" << std::endl;
        std::cout << "Increased " << m_characteristic_name << " characterictic, value to increase : " << m_value <<
                  " characteristic before: " << ch_value
                  << " characteristic after: " << character.get_characteristic(m_characteristic_name) << std::endl;
        m_decorator.apply_effect(character);
    }

    void discard_effect(Character &character) override
    {
        std::uint8_t ch_value = character.get_characteristic(m_characteristic_name);
        character.set_characteristic(m_characteristic_name, ch_value - m_value);
        std::cout << "Discard magic effect" << std::endl;
        std::cout << "Decreased " << m_characteristic_name << " characterictic, value to decrease : " << m_value <<
                  " characteristic before: " << ch_value
                  << " characteristic after: " << character.get_characteristic(m_characteristic_name) << std::endl;
        m_decorator.discard_effect(character);
    }

private:
    std::string m_characteristic_name;
    std::uint8_t m_value;
};

#endif // INCREASINGCHARACTERISTICDEFENSE_H
