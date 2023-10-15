#pragma once

class Player
{
public:
    Player(int x, int y, bool isPlayer1);
    void Update();
    void Draw();

private:
    int positionX;
    int positionY;
    int width;
    int height;
    int speed;
    bool isPlayer1;
};