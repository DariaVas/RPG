#include <plog/Log.h>
#include "IncreaseCharacteristicWeapon.h"
#include "Character.h"


IncreaseCharacteristicWeapon::IncreaseCharacteristicWeapon(std::unique_ptr <Weapon> &decorator, size_t value,
                                                           characteristic characteristic) :
        WeaponDecorator(decorator),
        m_characteristic(characteristic),
        m_value(value)
{
    LOGI << "Created decorator for weapon: IncreaseCharacteristicWeapon, "
         << " chosen characteristic: " << static_cast<int> (m_characteristic)
         << " points to increase : " << m_value;
}

void IncreaseCharacteristicWeapon::apply_effect(Character *character)
{
    character->increase_characteristic(m_characteristic, m_value);
    LOGI << "Thing: " << this->get_name() << ", applied effect \" increase characteristic\"" << std::endl;
    m_decorator->apply_effect(character);
}

void IncreaseCharacteristicWeapon::discard_effect(Character *character)
{
    character->decrease_characteristic(m_characteristic, m_value);
    LOGI << "Thing: " << this->get_name() << ", discarded effect \" increase characteristic\" " << std::endl;
    m_decorator->discard_effect(character);
}
