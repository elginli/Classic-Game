//
//  Collision.h
//  Classic Game
//
//  Created by Elgin Li on 9/22/24.
//

#pragma once
#include "SDL2/SDL.h"

class Collision
{
public:
    static bool CollisionManager(const SDL_Rect& rectA, const SDL_Rect& rectB);
};
