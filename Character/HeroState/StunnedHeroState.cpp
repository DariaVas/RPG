#include "StunnedHeroState.h"
#include <iostream>

StunnedHeroState::StunnedHeroState()
{

}

void StunnedHeroState::damage(Character* ch)
{
    std::cout << "A Hero cannot damage in a stunned state";
}

void StunnedHeroState::take_damage(Character* ch, Damage& dmg)
{
    std::cout << "A Hero cannot resist to damage in a stunned state";
    //Add code
}
