//
//  Actor.cpp
//  Classic Game
//
//  Created by Elgin Li on 9/20/24.
//

#include "Actor.h"

SDL_Texture* Actor::getTexture()
{
    return Tex;
}

SDL_Rect& Actor::getSource()
{
    return src;
}

SDL_Rect& Actor::getDest()
{
    return dest;
}

void Actor::setSource(int x, int y, int h, int w)
{
    src.x = x;
    src.y = y;
    src.h = h;
    src.w = w;
}

void Actor::setDest(int x, int y, int h, int w)
{
    dest.x = x;
    dest.y = y;
    dest.h = h;
    dest.w = w;
}

void Actor::CreateTexture(const char *address, SDL_Renderer *ren)
{
    Tex = SpriteRenderer::Texture(address, ren);
}
