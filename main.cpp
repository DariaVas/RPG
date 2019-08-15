#include <iostream>
#include "JsonHeroBuilder.h"

using namespace std;

int main()
{
    JsonHeroBuilder builder("character.json");

    std::vector <std::unique_ptr<Defense>> magic_things(builder.build_magic_defenses("first_hero"));
    std::vector <std::unique_ptr<Defense>> ph_things(builder.build_physical_defenses("first_hero"));
    std::vector <std::unique_ptr<Weapon>> w(builder.build_weapon("first_hero"));
    std::unique_ptr <Defense> s(builder.build_shield("first_hero"));
    Character ch;
    for (auto &thing : magic_things)
    {
        thing->apply_effect(ch);
        thing->discard_effect(ch);
    }
    for (auto &thing : ph_things)
    {
        thing->apply_effect(ch);
        thing->discard_effect(ch);

    }
    for (auto &thing : w)
    {
        thing->apply_effect(ch);
        thing->discard_effect(ch);

    }
    s->apply_effect(ch);
    s->discard_effect(ch);
//    Character ch;
//    amulet->apply_effect(ch);
//    amulet->discard_effect(ch);
    cout << "Hello World!" << endl;
    return 0;
}
