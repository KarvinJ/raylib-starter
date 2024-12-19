#include <raylib.h>

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 544;

typedef struct
{
    Rectangle bounds;
    Texture2D sprite;
    int speed;
    int score;
} Player;

Player player;

typedef struct
{
    Vector2 position;
    Vector2 velocity;
    int radius;
} Ball;

Ball ball;

bool isGamePaused;

Sound hitSound;

void update(float deltaTime)
{
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

    if (ball.position.y + ball.radius >= SCREEN_HEIGHT || ball.position.y - ball.radius <= 0)
    {
        ball.velocity.y *= -1;
    }

    if (ball.position.x + ball.radius >= SCREEN_WIDTH || ball.position.x - ball.radius <= 0)
    {
        ball.velocity.x *= -1;
    }

    // Check collision between a circle and a rectangle
    if (CheckCollisionCircleRec(ball.position, ball.radius, player.bounds))
    {
        ball.velocity.x *= -1;
        ball.velocity.y *= -1;

        player.score++;

        PlaySound(hitSound);
    }

    ball.position.x += ball.velocity.x * deltaTime;
    ball.position.y += ball.velocity.y * deltaTime;
}

void draw()
{
    BeginDrawing();

    ClearBackground(BLACK);

    DrawText(TextFormat("%i", player.score), 230, 20, 80, WHITE);

    DrawTexture(player.sprite, player.bounds.x, player.bounds.y, WHITE);

    DrawCircleV(ball.position, ball.radius, YELLOW);

    if (isGamePaused)
    {
        DrawText("Game Paused", 220, 100, 80, WHITE);
    }

    EndDrawing();
}

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Starter");
    SetTargetFPS(144);

    Texture2D sprite = LoadTexture("assets/img/alien.png");
    player = {{SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, (float)sprite.width, (float)sprite.height}, sprite, 600, 0};

    ball = {{SCREEN_WIDTH / 2 + 60, SCREEN_HEIGHT / 2}, {500, 500}, 15};

    InitAudioDevice(); // Initialize audio device, before loading sound and music.

    hitSound = LoadSound("assets/sounds/okay.wav");
    Music music = LoadMusicStream("assets/music/pixel3.mp3");

    music.looping = true;

    PlayMusicStream(music);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);

        float deltaTime = GetFrameTime();

        if (IsKeyPressed(KEY_SPACE))
        {
            isGamePaused = !isGamePaused;
        }

        if (!isGamePaused)
        {
            update(deltaTime);
        }

        draw();
    }

    // Unload texture data
    UnloadTexture(player.sprite);

    // Unload sound data
    UnloadSound(hitSound);
    UnloadMusicStream(music);

    CloseAudioDevice();

    CloseWindow();
}