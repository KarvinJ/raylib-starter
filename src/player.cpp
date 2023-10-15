#include "player.h"
#include <raylib.h>

Player::Player(float x, float y, bool isPlayer1)
{
    positionX = x;
    positionY = y;
    width = 16;
    height = 64;
    speed = 8;
    score = 0;
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
    DrawRectangleRounded(Rectangle{positionX, positionY, width, height}, 0.8, 0, WHITE);
}