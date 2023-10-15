#include "player.h"
#include <raylib.h>

Player::Player(int x, int y, bool isPlayer1)
{
    positionX = x;
    positionY = y;
    width = 16;
    height = 64;
    speed = 5;
    this->isPlayer1 = isPlayer1;
}

void Player::Update()
{
    if (isPlayer1)
    {
       //El origen en raylib sucede en la esquina superior izquierda, debido a esto debo restar para subir y sumar para bajar.
        if (IsKeyDown(KEY_W) && positionY >= 0)
            positionY -= speed;

        if (IsKeyDown(KEY_S) && positionY <= GetScreenHeight() - height)
            positionY += speed;
    }
    else{

        if (IsKeyDown(KEY_UP) && positionY >= 0)
            positionY -= speed;

        if (IsKeyDown(KEY_DOWN) && positionY <= GetScreenHeight() - height)
            positionY += speed;
    }
    
    
}

void Player::Draw()
{
    DrawRectangle(positionX, positionY, width, height, WHITE);
}