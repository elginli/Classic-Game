//
//  SpriteRenderer.h
//  Classic Game
//
//  Created by Elgin Li on 9/20/24.
//

#pragma once
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"

class SpriteRenderer{
public:
    static SDL_Texture* Texture(const char* filelocation, SDL_Renderer* ren);
};
