//
//  Background.h
//  Classic Game
//
//  Created by Elgin Li on 9/20/24.
//

#pragma once
#include "Actor.h"

class Background : public Actor
{
public:
    void G1_Update(float deltaTime);
    void G2_Update(float deltaTime);
    void Render(SDL_Renderer* ren, float deltaTime);
    void RenderGround(SDL_Renderer* ren);
    void RenderPipe(SDL_Renderer* ren);
    bool Pipe1_Top_Update(int RandIncY, float deltaTime, int& score);
    bool Pipe1_Bot_Update(int RandIncY, float deltaTime);
    bool Pipe2_Top_Update(int RandIncY, float deltaTime, int& score);
    bool Pipe2_Bot_Update(int RandIncY, float deltaTime);
private:
    float gLoc1 = 0.0f;
    float gLoc2 = 855.0f;
    int pipeLoc1 = 500;
    int pipeLoc2 = 800;
    int randIncY1 = 0;
    int randIncY2 = 0;
    float speed = 187.5f;
};
