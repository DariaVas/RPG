#include "defense.h"
#include "DefenseDecorator.h"

DefenseDecorator::DefenseDecorator(std::unique_ptr<Defense>& decorator) :
        Defense(decorator->get_name(), decorator->get_resist_type(),
                decorator->get_resist_power()),
        m_decorator(std::move(decorator))
{

}

void DefenseDecorator::apply_effect(Character &character)
{
    m_decorator->apply_effect(character);
}


void DefenseDecorator:: discard_effect(Character &character)
{
    m_decorator->apply_effect(character);
}

DefenseDecorator::~DefenseDecorator()
{
    
}
