#pragma once

class Ball
{
public:
    Ball(float x, float y);
    void ResetPosition();
    void Update();
    void Draw();

public:
    float positionX;
    float positionY;
    int velocityX;
    int velocityY;
    int radius;
};