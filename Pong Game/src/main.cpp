#include <raylib.h>
#include "Core.h"
#include "ball.h"
#include "Paddle.h"

int winHeight, winWidth;

void DrawDottedLine(int points)
{
    float d = GetScreenHeight()/ points;
    float point;
    for(int i = 0; i < points; i++)
    {
        DrawRectangle(winWidth/2 -2, d*i, 4, d-(d/3), WHITE);
    }
}

int main()
{
    winWidth = 1200;
    winHeight = 800;
    
    InitWindow(winWidth, winHeight, "Pong Game");

    SetTargetFPS(60);


    Ball ball(winWidth/2, winHeight/2, 10, 10, 20, WHITE);

    Paddle paddle(10, winHeight/2 - 75,
                 25, 200, 5);

    Paddle aiPaddle(winWidth - 10 - 25, winHeight/2 - 75,
                 25, 200, 8);

    // Game loop 
    while (!WindowShouldClose())
    {
        ball.Update();
        paddle.Update();
        aiPaddle.AiUpdate(ball.GetYpos());

        if(paddle.isColliding(ball.GetCenter(), ball.GetRadius()))
            ball.CollisionDetected();

        if(aiPaddle.isColliding(ball.GetCenter(), ball.GetRadius()))
            ball.CollisionDetected();    

        BeginDrawing();
        ClearBackground(BLACK);

        DrawDottedLine(20);

        paddle.Draw();
        aiPaddle.Draw();
        ball.Draw();

        DrawText(TextFormat("%i", ball.playerScore), winWidth/3 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", ball.cpuScore), 2 * winWidth/3 - 20, 20, 80, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}