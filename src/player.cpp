#include "player.h"

Player::Player(float positionX, float positionY)
{
    bounds = Rectangle{positionX, positionY, 16, 84};
    speed = 800;
    score = 0;
}

void Player::Update(float deltaTime)
{
    if (IsKeyDown(KEY_W) && bounds.y >= 0)
        bounds.y -= speed * deltaTime;

    if (IsKeyDown(KEY_S) && bounds.y <= GetScreenHeight() - bounds.height)
        bounds.y += speed * deltaTime;
}

void Player::Draw()
{
    DrawRectangleRounded(bounds, 0.8, 0, WHITE);
}