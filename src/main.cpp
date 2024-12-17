#include <raylib.h>
#include "ball.h"

typedef struct
{
    Rectangle bounds;
    int speed;
    int score;
} Player;

int main()
{
    const int SCREEN_WIDTH = 960;
    const int SCREEN_HEIGHT = 640;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong!");
    SetTargetFPS(144);

    Player player = {{SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 32, 32}, 600, 0};

    Ball ball = Ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    InitAudioDevice(); // Initialize audio device, before loading sound and music.

    Sound hitSound = LoadSound("assets/sounds/okay.wav");
    Music music = LoadMusicStream("assets/music/pixel3.mp3");

    music.looping = true;

    PlayMusicStream(music);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);

        float deltaTime = GetFrameTime();

        if (IsKeyDown(KEY_W) && player.bounds.y >= 0)
        {
            player.bounds.y -= player.speed * deltaTime;
        }

        else if (IsKeyDown(KEY_S) && player.bounds.y <= SCREEN_HEIGHT - player.bounds.height)
        {
            player.bounds.y += player.speed * deltaTime;
        }

        else if (IsKeyDown(KEY_D) && player.bounds.x <= SCREEN_WIDTH - player.bounds.width)
        {
            player.bounds.x += player.speed * deltaTime;
        }

        else if (IsKeyDown(KEY_A) && player.bounds.x > 0)
        {
            player.bounds.x -= player.speed * deltaTime;
        }

        ball.Update(deltaTime);

        // Check collision between a circle and a rectangle
        if (CheckCollisionCircleRec(ball.position, ball.radius, player.bounds))
        {
            ball.velocity.x *= -1;
            ball.velocity.y *= -1;
            
            PlaySound(hitSound);
        }

        BeginDrawing();

        ClearBackground(BLACK);

        DrawText(TextFormat("%i", player.score), 230, 20, 80, WHITE);

        DrawRectangleRec(player.bounds, WHITE);

        ball.Draw();

        EndDrawing();
    }

    // Unload sound data
    UnloadSound(hitSound);
    UnloadMusicStream(music);

    CloseAudioDevice();

    CloseWindow();
}