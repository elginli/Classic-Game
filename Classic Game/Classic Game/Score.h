//
//  Score.h
//  Classic Game
//
//  Created by Elgin Li on 9/25/24.
//

#pragma once
#include "Actor.h"
#include <vector>

class Score : public Actor {
public:
    bool CreateTexture(SDL_Renderer* renderer);
    void UpdateScore(int& score);
    void Render(SDL_Renderer* renderer, float deltaTime);
    void Shutdown();

private:
    SDL_Texture* digitTextures[10];
    std::vector<int> digits;
};
