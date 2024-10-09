//
//  Collision.cpp
//  Classic Game
//
//  Created by Elgin Li on 9/22/24.
//

#include "Collision.h"

bool Collision::CollisionManager(const SDL_Rect& rectA, const SDL_Rect& rectB){
    if (rectA.x + rectA.w <= rectB.x)
    {
        return false;
    }
    if(rectA.x >= rectB.x + rectB.w)
    {
        return false;
    }
    if(rectA.y + rectA.h <= rectB.y)
    {
        return false;
    }
    if(rectA.y >= rectB.y + rectB.h)
    {
        return false;
    }
    return true;
}
