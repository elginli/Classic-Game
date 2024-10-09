//
//  Player.h
//  Classic Game
//
//  Created by Elgin Li on 9/20/24.
//

#pragma once
#include "Actor.h"

class Player : public Actor
{
public:
    void Render(SDL_Renderer* ren, float deltaTime);
    void CreateTex1(const char* address, SDL_Renderer* ren);
    void CreateTex2(const char* address, SDL_Renderer* ren);
    void ApplyGravity(float deltaTime);
    void Jump(float deltaTime);

private:
    float gravity = 30.0f;
    int y = 380;
    double accel = 0.0;
    double timer = 0.0;
    int currentFrame = 0;
    SDL_Texture* Tex1;
    SDL_Texture* Tex2;
};
