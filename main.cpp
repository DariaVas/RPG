#include <iostream>
#include <plog/Log.h>
#include "Game.h"
#include "ConfigGameCreator.h"
#include "RandomGameCreator.h"

using namespace std;

int main()
{
    try
    {
      plog::init(plog::debug, "./RPG.log");
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
      LOGI << "Game started";
      Game game(game_creator);
      game.play();
    }
    catch (const std::exception& ex)
    {
        std::cout << "The error happend: " <<  ex.what();
        return 1;
    }
    return 0;
}
