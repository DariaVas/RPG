#pragma once
#ifndef INCREASECHANCEOFDODGE_H
#define INCREASECHANCEOFDODGE_H

#include "DefenseDecorator.h"

class IncreaseChanceOfDodge final : public DefenseDecorator
{
public:
    IncreaseChanceOfDodge(std::unique_ptr <Defense> &decorator, size_t value);

    void apply_effect(Character &character) override;

    void discard_effect(Character &character) override;

private:
    size_t m_dodge_power;
};

#endif // INCREASECHANCEOFDODGE_H
