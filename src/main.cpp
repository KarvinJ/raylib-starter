#include <raylib.h>
#include "ball.h"
#include "player.h"


int main()
{
    Color darkGreen = Color{0, 0, 0, 0};

    const int screenWidth = 960;
    const int screenHeight = 640;

    InitWindow(screenWidth, screenHeight, "Pong!");
    SetTargetFPS(60);

    Player player = Player(10, 300, true);

    Ball ball = Ball();

    Player player2 = Player(934, 300, false);

    while (!WindowShouldClose())
    {
        player.Update();
        ball.Update();
        player2.Update();

        ClearBackground(darkGreen);

        BeginDrawing();

        player.Draw();
    
        ball.Draw();

        player2.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}