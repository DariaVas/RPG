#include <iostream>
#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <plog/Log.h>
#include "Game.h"
#include "Utils.h"
#include "ConfigGameCreator.h"
#include "RandomGameCreator.h"

using namespace std;

void handler(int sig)
{
  void *array[10];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 10);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}

int main()
{
    try
    {
        signal(SIGSEGV, handler);
        plog::init(plog::debug, "./RPG.log", 60000000);
        std::cout << "How do you want to initialize heroes? \n"
                     "1. Randomly generate heroes \n"
                     "2. Load heroes configuration from json configuration file \n";
        size_t choose;
        std::cin >> choose;
        std::unique_ptr <IGameCreator> game_creator;
        switch (choose)
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
    catch (const utils::HeroDied &h)
    {
        std::cout << "♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥\n";
        std::cout << "Game over, " << h.what() << " died\n";
        std::cout << "♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥\n";
        
        return 1;
    }
    catch (const std::exception &ex)
    {
        std::cout << "The error happend: " << ex.what();
        return 1;
    }
    return 0;
}
