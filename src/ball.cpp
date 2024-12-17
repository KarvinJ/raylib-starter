#include "ball.h"

Ball::Ball(float positionX, float positionY)
{
    position = Vector2{positionX, positionY};
    velocity = Vector2{400, 400};
    radius = 15;
}

void Ball::Update(float deltaTime)
{
    if (position.y + radius >= GetScreenHeight() || position.y - radius <= 0)
    {
        velocity.y *= -1;
    }

    if (position.x + radius >= GetScreenWidth() || position.x - radius <= 0)
    {
        velocity.x *= -1;
    }

    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
}

void Ball::Draw()
{
    DrawCircleV(position, radius, YELLOW);
}