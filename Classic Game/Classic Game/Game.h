//
//  Game.h
//  Classic Game
//
//  Created by Elgin Li on 9/15/24.
//

#pragma once
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SpriteRenderer.h"
#include "Player.h"
#include "Background.h"
#include "Collision.h"
#include "Score.h"

// Game class
class Game
{
public:
    Game();
    // Initialize the game
    bool Initialize();
    // Runs the game loop until the game is over
    void RunLoop();
    // Shutdown the game
    void Shutdown();
    float deltaTime;
    int score = 0;
private:
    // Helper functions for the game loop
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();
    Player p;
    Background b;
    Background g1, g2, g3;
    Background pipe1_top;
    Background pipe1_bot;
    Background pipe2_top;
    Background pipe2_bot;
    Score mScore;
    int randInc1 = rand() % 201 - 90;
    int randInc2 = rand() % 201 - 90;
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    Uint32 mTicksCount;
    bool mIsRunning;
};
