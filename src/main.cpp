#include <raylib.h>
#include "ball.h"
#include "player.h"

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};
    Color green = Color{38, 185, 154, 255};
    Color lightGreen = Color{129, 204, 184, 255};

    const int screenWidth = 960;
    const int screenHeight = 640;

    InitWindow(screenWidth, screenHeight, "Pong!");
    SetTargetFPS(60);

    Player player = Player(10, screenHeight / 2, true);

    Ball ball = Ball(screenWidth / 2, screenHeight / 2);

    Player player2 = Player(screenWidth -26, screenHeight / 2, false);

    while (!WindowShouldClose())
    {
        player.Update();
        ball.Update();
        player2.Update();

        //Check collision between a circle and a rectangle
        if (CheckCollisionCircleRec(Vector2{ball.positionX, ball.positionY}, ball.radius, Rectangle{player.positionX, player.positionY, player.width, player.height}))
            ball.velocityX *= -1;
        
        if (CheckCollisionCircleRec(Vector2{ball.positionX, ball.positionY}, ball.radius, Rectangle{player2.positionX, player2.positionY, player2.width, player2.height}))
            ball.velocityX *= -1;

        if (ball.positionX > 960)
        {
            player.score++;
            ball.ResetPosition();
        }

        else if (ball.positionX < 0)
        {
            player2.score++;
            ball.ResetPosition();
        }
        

        ClearBackground(darkGreen);

        BeginDrawing();

        //Right side color
        DrawRectangle(screenWidth/2, 0, screenWidth/2, screenHeight, green);

        // circle for the half of the court.
        DrawCircle(screenWidth/2, screenHeight/2, 150, lightGreen);

        DrawLine(screenWidth /2, screenHeight, screenWidth / 2, 0, WHITE);

        DrawText(TextFormat("%i", player.score), 230, 20, 80, WHITE);

        DrawText(TextFormat("%i", player2.score), screenWidth - 250, 20, 80, WHITE);

        player.Draw();
    
        ball.Draw();

        player2.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}