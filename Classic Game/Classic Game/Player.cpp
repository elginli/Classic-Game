//
//  Player.cpp
//  Classic Game
//
//  Created by Elgin Li on 9/20/24.
//

#include "Player.h"

void Player::Render(SDL_Renderer* ren, float deltaTime)
{
 
    const float frameDuration = 0.1f;

    timer += deltaTime;

    if (timer >= frameDuration)
    {
        currentFrame = (currentFrame + 1) % 3;
        timer = 0.0f;

    }
    
    if (currentFrame == 0) {
        SDL_RenderCopyEx(ren, getTexture(), &getSource(), &getDest(), 0, NULL, SDL_FLIP_NONE);
    }
    else if (currentFrame == 1) {
        SDL_RenderCopyEx(ren, Tex1, &getSource(), &getDest(), 0, NULL, SDL_FLIP_NONE);
    }
    else if (currentFrame == 2) {
        SDL_RenderCopyEx(ren, Tex2, &getSource(), &getDest(), 0, NULL, SDL_FLIP_NONE);
    }

}

void Player::ApplyGravity(float deltaTime)
{
        const float maxFallSpeed = 30.0f;

        accel += gravity * deltaTime;
        if (accel > maxFallSpeed)
        {
            accel = maxFallSpeed;
        }

        y += accel * deltaTime * 45;
        setDest(25, static_cast<int>(y), 38, 51);    
}

void Player::Jump(float deltaTime)
{

    const float jumpForce = -600.0f;
    accel = jumpForce * deltaTime;
    ApplyGravity(deltaTime);
}


void Player::CreateTex1(const char *address, SDL_Renderer *ren)
{
    Tex1 = SpriteRenderer::Texture(address, ren);
}

void Player::CreateTex2(const char *address, SDL_Renderer *ren)
{
    Tex2 = SpriteRenderer::Texture(address, ren);
}
