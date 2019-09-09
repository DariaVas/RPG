#include "Defense.h"
#include "DefenseDecorator.h"
#include "Character.h"


DefenseDecorator::DefenseDecorator(std::unique_ptr <Defense> &defense) :
        Defense(defense->get_name(), defense->get_resist_type(),
                defense->get_resist_power()),
        m_defense(std::move(defense))
{

}

void DefenseDecorator::apply_effect(Character *character)
{

    m_defense->apply_effect(character);
}


void DefenseDecorator::discard_effect(Character *character)
{
    m_defense->apply_effect(character);
}

void DefenseDecorator::reduce_durability(unsigned int value)
{
    m_defense->reduce_durability(value);
}

damage_types DefenseDecorator::get_resist_type()
{
    return m_defense->get_resist_type();
}

size_t DefenseDecorator::get_resist_power()
{
    return m_defense->get_resist_power();
}

bool DefenseDecorator::is_broken()
{
    return m_defense->is_broken();
}

const std::string& DefenseDecorator::get_name()
{
    return m_defense->get_name();
}

size_t DefenseDecorator::get_weight()
{
    return m_defense->get_weight();
}
