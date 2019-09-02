#include "Defense.h"
#include "DefenseDecorator.h"
#include "Character.h"


DefenseDecorator::DefenseDecorator(std::unique_ptr <Defense> &decorator) :
        Defense(decorator->get_name(), decorator->get_resist_type(),
                decorator->get_resist_power()),
        m_decorator(std::move(decorator))
{

}

void DefenseDecorator::apply_effect(Character *character)
{

    m_decorator->apply_effect(character);
}


void DefenseDecorator::discard_effect(Character *character)
{
    m_decorator->apply_effect(character);
}

DefenseDecorator::~DefenseDecorator()
{

}

void DefenseDecorator::reduce_durability(unsigned int value)
{
    m_decorator->reduce_durability(value);
}

damage_types DefenseDecorator::get_resist_type()
{
    return m_decorator->get_resist_type();
}

size_t DefenseDecorator::get_resist_power()
{
    return m_decorator->get_resist_power();
}

bool DefenseDecorator::is_broken()
{
    return m_decorator->is_broken();
}

const std::string& DefenseDecorator::get_name()
{
    return m_decorator->get_name();
}

size_t DefenseDecorator::get_weight()
{
    return m_decorator->get_weight();
}
