//
//  SpriteRenderer.cpp
//  Classic Game
//
//  Created by Elgin Li on 9/20/24.
//

#include "SpriteRenderer.h"

SDL_Texture* SpriteRenderer::Texture(const char *filelocation, SDL_Renderer *ren)
{
    SDL_Surface* surface = IMG_Load(filelocation);
    if(!surface){
        SDL_Log("Failed to load image: %s. IMG_Error: %s", filelocation, IMG_GetError());
        return nullptr;
    }
    
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surface);
    SDL_FreeSurface(surface);
    
    if(!tex){
        SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
    }
    
    return tex;
}
