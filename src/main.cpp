#include <raylib.h>
#include "ball.h"
#include "player.h"

int main()
{
    const int SCREEN_WIDTH = 960;
    const int SCREEN_HEIGHT = 640;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong!");
    SetTargetFPS(144);

    Player player = Player(10, SCREEN_HEIGHT / 2);

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

        player.Update(deltaTime);
        ball.Update(deltaTime);

        // Check collision between a circle and a rectangle
        if (ball.HasCollideWithPlayer(player.bounds))
        {
            ball.velocity.x *= -1;
            PlaySound(hitSound);
        }

        BeginDrawing();

        ClearBackground(BLACK);

        DrawText(TextFormat("%i", player.score), 230, 20, 80, WHITE);

        player.Draw();

        ball.Draw();

        EndDrawing();
    }

    // Unload sound data
    UnloadSound(hitSound);
    UnloadMusicStream(music);

    CloseAudioDevice();

    CloseWindow();
}