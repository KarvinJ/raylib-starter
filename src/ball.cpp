#include "ball.h"
#include <raylib.h>

Ball::Ball(float x, float y)
{
    positionX = x;
    positionY = y;
    velocityX = 5;
    velocityY = 5;
    radius = 15;
}

void Ball::ResetPosition()
{
    positionX = 960 / 2;
    positionY = 640 / 2;

    velocityX *= -1;
    velocityY *= -1;
}

void Ball::Update()
{
    positionX += velocityX;
    positionY += velocityY;

    if (positionY + radius >= GetScreenHeight() || positionY - radius <= 0)
        velocityY *= -1;
}

void Ball::Draw()
{
    DrawCircle(positionX, positionY, radius, YELLOW);
}