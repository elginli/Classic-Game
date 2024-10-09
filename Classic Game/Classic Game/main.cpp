//
//  main.cpp
//  Classic Game
//
//  Created by Elgin Li on 9/15/24.
//
#include "Game.h"

int main(int argc, char** argv)
{
    Game game;
    bool success = game.Initialize();
    if (success)
    {
        game.RunLoop();
    }
    game.Shutdown();
    return 0;
}

