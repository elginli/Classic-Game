//
//  Background.cpp
//  Classic Game
//
//  Created by Elgin Li on 9/20/24.
//

#include "Background.h"


void Background::Render(SDL_Renderer *ren, float deltatime)
{
    SDL_RenderCopy(ren, getTexture(), NULL, NULL);
}

void Background::RenderGround(SDL_Renderer *ren)
{
    SDL_RenderCopy(ren, getTexture(), &getSource(), &getDest());
}

void Background::RenderPipe(SDL_Renderer *ren)
{
    SDL_RenderCopy(ren, getTexture(), &getSource(), &getDest());
}

void Background::G1_Update(float deltaTime)
{
    if (gLoc1 <= -850){
        gLoc1 = 855;
    }else{
        gLoc1 -= static_cast<int>(speed * deltaTime);
    }
    setDest(static_cast<int>(gLoc1), 620, 185, 855);
    
}

void Background::G2_Update(float deltaTime)
{
    if (gLoc2 <= -850){
        gLoc2 = 855 ;
    }else{
        gLoc2 -= static_cast<int>(speed * deltaTime);
    }
    setDest(static_cast<int>(gLoc2), 620, 185, 855);         
}

bool Background::Pipe1_Top_Update(int RandIncY, float deltaTime, int& score)
{
    randIncY1 = RandIncY;
    if(pipeLoc1 <= -75)
    {
        score ++;
        pipeLoc1 = 500;        
        return true;
    }
    else
    {
        pipeLoc1 -= static_cast<int>(speed * deltaTime);
        setDest(pipeLoc1, -200 + randIncY1, 400, 75);
        return false;
    }
}

bool Background::Pipe1_Bot_Update(int RandIncY, float deltaTime)
{
    randIncY1 = RandIncY;
    if(pipeLoc1 <= -75)
    {
        pipeLoc1 = 500;
        return true;
    }
    else
    {
        pipeLoc1 -= static_cast<int>(speed * deltaTime);
        setDest(pipeLoc1, 350 + randIncY1, 400, 75);
        return false;
    }
}

bool Background::Pipe2_Top_Update(int RandIncY, float deltaTime, int& score)
{
    randIncY2 = RandIncY;
    if(pipeLoc2 <= -75)
    {
        score ++;
        pipeLoc2 = 500;
        return true;
    }
    else
    {
        pipeLoc2 -= static_cast<int>(speed * deltaTime);
        setDest(pipeLoc2, -200 + randIncY2, 400, 75);
        return false;
    }
}

bool Background::Pipe2_Bot_Update(int RandIncY, float deltaTime)
{
    randIncY2 = RandIncY;
    if(pipeLoc2 <= -75)
    {
        pipeLoc2 = 500;
        return true;
    }
    else
    {
        pipeLoc2 -= static_cast<int>(speed * deltaTime);
        setDest(pipeLoc2, 350 + randIncY2, 400, 75);
        return false;
    }
}

