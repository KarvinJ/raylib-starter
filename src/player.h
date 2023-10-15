#pragma once

class Player
{
public:
    Player(float x, float y, bool isPlayer1);
    void Update();
    void Draw();

public:
    float positionX;
    float positionY;
    float width;
    float height;
    int speed;
    int score;
    bool isPlayer1;
};