#pragma once

#include <raylib.h>

class Ball
{
public:
    Ball(float positionX, float positionY);
    void Update(float deltaTime);
    void Draw();

public:
    Vector2 position;
    Vector2 velocity;
    int radius;
};