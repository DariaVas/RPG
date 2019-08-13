#pragma once

#ifndef INCREASECRITICALHITMODIFIER_H
#define INCREASECRITICALHITMODIFIER_H

#include "weapondecorator.h"
#include "Character/Character.h"

class IncreaseCriticalHitModifier final : public WeaponDecorator
{
public:
    IncreaseCriticalHitModifier(Weapon &decorator, size_t value);

    Damage generate_damage(Character &character) override;

private:
    size_t m_increase_value;
};


#endif // INCREASECRITICALHITMODIFIER_H
