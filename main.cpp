#include <iostream>
#include "JsonHeroBuilder.h"

using namespace std;

int main()
{
    JsonHeroBuilder builder("character.json");
    std::unique_ptr <Defense> amulet(builder.build_magic_amulet("second_hero"));
    Character ch;
    amulet->apply_effect(ch);
    amulet->discard_effect(ch);
    cout << "Hello World!" << endl;
    return 0;
}
