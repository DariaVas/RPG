#include <iostream>
#include "Game.h"
#include "ConfigGameCreator.h"
#include "RandomGameCreator.h"

using namespace std;

int main()
{
    try
    {
      std::cout << "How do you want to initialize heroes? \n"
                   "1. Randomly generate heroes \n"
                   "2. Load heroes configuration from json configuration file \n";
      size_t choose = 2;
//      std::cin >> choose;
      std::unique_ptr<GameCreator> game_creator;
      switch(choose)
      {
        case 1:
          game_creator.reset(new RandomGameCreator());
          break;
       case 2:
          game_creator.reset(new ConfigGameCreator());
          break;
        default:
          std::cout << "Unknown choice" << std::endl;
          return 1;
          break;
      }
      Game game(game_creator);
      game.play();
    }
    catch (const std::exception& ex)
    {
        std::cout << "The error happend: " <<  ex.what();
        return 1;
    }

//    JsonHeroBuilder builder("character.json");
//    builder.build_first_hero();



//    JsonHeroBuilder builder("character.json");

//    std::vector <std::unique_ptr<Defense>> magic_things(builder.build_magic_defenses("first_hero"));
//    std::vector <std::unique_ptr<Defense>> ph_things(builder.build_physical_defenses("first_hero"));
//    std::vector <std::unique_ptr<Weapon>> w(builder.build_weapon("first_hero"));
//    std::unique_ptr <Defense> s(builder.build_shield("first_hero"));
//    Character ch;
//    for (auto &thing : magic_things)
//    {
//        thing->apply_effect(&ch);
//        thing->discard_effect(&ch);
//    }
//    for (auto &thing : ph_things)
//    {
//        thing->apply_effect(&ch);
//        thing->discard_effect(&ch);

//    }
//    for (auto &thing : w)
//    {
//        thing->apply_effect(&ch);
//        thing->discard_effect(&ch);

//    }
//    s->apply_effect(&ch);
//    s->discard_effect(&ch);


//    Character ch;
//    amulet->apply_effect(ch);
//    amulet->discard_effect(ch);
    cout << "Hello World!" << endl;
    return 0;
}
