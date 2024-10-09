//
//  Score.cpp
//  Classic Game
//
//  Created by Elgin Li on 9/25/24.
//

#include "Score.h"
#include <string>

bool Score::CreateTexture(SDL_Renderer* renderer)
{
    for (int i = 0; i < 10; i++)
    {
        std::string path = "images/" + std::to_string(i) + ".png";
        digitTextures[i] = SpriteRenderer::Texture(path.c_str(), renderer);
        if (!digitTextures[i]) {
            return false;
        }
    }
    return true;
}

void Score::UpdateScore(int& score)
{
    digits.clear();
    
    int displayScore = score;
    if (displayScore == 0)
    {
        digits.push_back(0);
    }
    else
    {
        while (displayScore > 0)
        {
            digits.push_back(displayScore % 10);
            displayScore /= 10;
        }
    }

    std::reverse(digits.begin(), digits.end());

    int digitCount = static_cast<int>(digits.size());
    int xOffset = 500 / 2 - (digitCount * 40 / 2);
    for (int i = 0; i < digits.size(); i++) {
        setDest(xOffset + (i * 40), 20, 40, 70);
    }
}

void Score::Render(SDL_Renderer* ren, float deltaTime)
{
    for (int i = 0; i < digits.size(); i++) {
        int digitIndex = digits[i];
        
        int digitCount = static_cast<int>(digits.size());
        int xOffset = 500 / 2 - (digitCount * 40 / 2);
        
        SDL_Rect src = {0, 0, 100, 100};
        SDL_Rect dest = {xOffset + (i * 40), 20, 40, 70};
        
        SDL_RenderCopyEx(ren, digitTextures[digitIndex], &src, &dest, 0, NULL, SDL_FLIP_NONE);
    }
}

void Score::Shutdown()
{
    for (int i = 0; i < 10; i++)
    {
        if (digitTextures[i])
        {
            SDL_DestroyTexture(digitTextures[i]);
            digitTextures[i] = nullptr;
        }
    }
}
