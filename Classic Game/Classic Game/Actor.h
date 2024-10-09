//
//  Actor.h
//  Classic Game
//
//  Created by Elgin Li on 9/20/24.
//


#pragma once
#include "SpriteRenderer.h"

class Actor
{
public:
    SDL_Texture* getTexture();
    SDL_Rect& getSource();
    SDL_Rect& getDest();
    void setSource(int x, int y, int h, int w);
    void setDest(int x, int y, int h, int w);
    void CreateTexture(const char* address, SDL_Renderer* ren);
    void virtual Render(SDL_Renderer* ren, float deltaTime) = 0;
    
private:
    SDL_Rect src, dest;
    SDL_Texture* Tex;
    
};
