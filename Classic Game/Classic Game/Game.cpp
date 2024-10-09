//
//  Game.cpp
//  Classic Game
//
//  Created by Elgin Li on 9/15/24.
//
#include "Game.h"
#include "SpriteRenderer.h"
#include "Player.h"
#include "Background.h"
#include "Collision.h"  
#include "Score.h"

Game::Game()  
:mWindow(nullptr)
,mRenderer(nullptr)
,mTicksCount(0)
,mIsRunning(true)
{
    p.setSource(0,0,24,34);
    p.setDest(25, 760/2, 42, 57);
    g1.setSource(0, 0, 112, 336);
    g1.setDest(0, 620, 185, 855);
    g2.setSource(0, 0, 112, 336);
    g2.setDest(855, 620, 185, 855);
    pipe1_top.setSource(0, 0, 320, 52);
    pipe1_top.setDest(500, -200, 400, 75);
    pipe1_bot.setSource(0, 0, 320, 52);
    pipe1_bot.setDest(500, 350, 400, 75);
    pipe2_top.setSource(0, 0, 320, 52);
    pipe2_top.setDest(800, -200, 400, 75);
    pipe2_bot.setSource(0, 0, 320, 52);
    pipe2_bot.setDest(800, 350, 400, 75);
}

bool Game::Initialize()
{
    // Initialize SDL
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if (sdlResult != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }
    
    // Create an SDL Window
    mWindow = SDL_CreateWindow(
        "Flappy Bird", // Window title
        SDL_WINDOWPOS_CENTERED,    // Top left x-coordinate of window
        SDL_WINDOWPOS_CENTERED,    // Top left y-coordinate of window
        500,    // Width of window
        760,    // Height of window
        0        // Flags (0 for no flags set)
    );

    if (!mWindow)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }
    
    // Create SDL renderer
    mRenderer = SDL_CreateRenderer(
        mWindow, // Window to create renderer for
        -1,         // Usually -1
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (!mRenderer)
    {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }
    //
    
    if(IMG_Init(IMG_INIT_PNG) == 0){
        SDL_Log("Failed to initialize SDL_image: %s", SDL_GetError());
        return false;
    }
    
    if (!mScore.CreateTexture(mRenderer)) {
        SDL_Log("Failed to initialize score: %s", SDL_GetError());
        return false;
    }
    
    p.CreateTexture("images/bluebird-downflap.png", mRenderer);
    p.CreateTex1("images/bluebird-midflap.png", mRenderer);
    p.CreateTex2("images/bluebird-upflap.png", mRenderer);
    b.CreateTexture("images/background-night.png", mRenderer);
    g1.CreateTexture("images/base.png", mRenderer);
    g2.CreateTexture("images/base.png", mRenderer);
    pipe1_top.CreateTexture("images/pipe_Above.png", mRenderer);
    pipe1_bot.CreateTexture("images/pipe_Below.png", mRenderer);
    pipe2_top.CreateTexture("images/pipe_Above.png", mRenderer);
    pipe2_bot.CreateTexture("images/pipe_Below.png", mRenderer);
    
    return true;
}

void Game::RunLoop()
{
    while (mIsRunning)
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
    Shutdown();
}

void Game::ProcessInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) {
                mIsRunning = false;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
        {
            p.Jump(deltaTime);

        }
    }
    // Get state of keyboard
    const Uint8* state = SDL_GetKeyboardState(NULL);
    // If escape is pressed, also end loop
    if (state[SDL_SCANCODE_ESCAPE])
    {
        mIsRunning = false;
    }
    
}

void Game::UpdateGame()
{
    // Wait until 16ms has elapsed since last frame
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));

    // Delta time is the difference in ticks from last frame
    // (converted to seconds)
    deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
    
    
    // Clamp maximum delta time value
    if (deltaTime > 0.05f)
    {
        deltaTime = 0.05f;
    }
    
    p.ApplyGravity(deltaTime);
    g1.G1_Update(deltaTime);
    g2.G2_Update(deltaTime);
    mScore.UpdateScore(score);
    
    bool c1 = false;
    bool c2 = false;
    bool c3 = false;
    bool c4 = false;
    
    c1 = pipe1_top.Pipe1_Top_Update(randInc1, deltaTime, score);
    c2 = pipe1_bot.Pipe1_Bot_Update(randInc1, deltaTime);
    c3 = pipe2_top.Pipe2_Top_Update(randInc2, deltaTime, score);
    c4 = pipe2_bot.Pipe2_Bot_Update(randInc2, deltaTime);
    
    if (c1 && c2)
    {
        srand(SDL_GetTicks());
        randInc1 = rand() % 201 - 90;
        pipe1_top.Pipe1_Top_Update(randInc1, deltaTime, score);
        pipe1_bot.Pipe1_Bot_Update(randInc1, deltaTime);
    }
    
    if (c3 && c4)
    {
        srand(SDL_GetTicks());
        randInc2 = rand() % 201 - 90;
        pipe2_top.Pipe2_Top_Update(randInc2, deltaTime, score);
        pipe2_bot.Pipe2_Bot_Update(randInc2, deltaTime);
    }
    
    SDL_Rect& pRect = p.getDest();
    SDL_Rect& pipe1TopRect = pipe1_top.getDest();
    SDL_Rect& pipe1BotRect = pipe1_bot.getDest();
    SDL_Rect& pipe2TopRect = pipe2_top.getDest();
    SDL_Rect& pipe2BotRect = pipe2_bot.getDest();
    SDL_Rect& g1Rect = g1.getDest();
    SDL_Rect& g2Rect = g2.getDest();
    
    if(Collision::CollisionManager(pRect, pipe1TopRect) ||
       Collision::CollisionManager(pRect, pipe1BotRect) ||
       Collision::CollisionManager(pRect, pipe2TopRect) ||
       Collision::CollisionManager(pRect, pipe2BotRect) ||
       Collision::CollisionManager(pRect, g1Rect) ||
       Collision::CollisionManager(pRect, g2Rect) )
    {
        mIsRunning = false;
    }
    // Update tick counts (for next frame)
    mTicksCount = SDL_GetTicks();
}

void Game::GenerateOutput()
{

    SDL_SetRenderDrawColor(
        mRenderer,
        0,
        0,
        0,
        0       
    );
    
    // Clear back buffer
    SDL_RenderClear(mRenderer);
    
    b.Render(mRenderer, deltaTime);
    pipe1_top.RenderPipe(mRenderer);
    pipe1_bot.RenderPipe(mRenderer);
    pipe2_top.RenderPipe(mRenderer);
    pipe2_bot.RenderPipe(mRenderer);
    g1.RenderGround(mRenderer);
    g2.RenderGround(mRenderer);
    p.Render(mRenderer, deltaTime);
    mScore.Render(mRenderer, deltaTime);
    // Swap front buffer and back buffer
    SDL_RenderPresent(mRenderer);
}

void Game::Shutdown()
{
    mScore.Shutdown();
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    IMG_Quit();
    SDL_Quit();
}

