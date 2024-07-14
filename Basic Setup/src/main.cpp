#include <raylib.h>

int winHeight, winWidth;

int main()
{
    winWidth = 1000;
    winHeight = 1000;
    
    InitWindow(winWidth, winHeight, "Testing Raylib");

    SetTargetFPS(60);

    int ballx = winWidth/2;
    int bally = winHeight/2;

    // Game loop 
    while (!WindowShouldClose())
    {
        // 1. Event Handling
        if(IsKeyDown(KEY_RIGHT))
            ballx++;
        else if(IsKeyDown(KEY_LEFT))
            ballx--;

        if(IsKeyDown(KEY_UP))
            bally--;
        else if(IsKeyDown(KEY_DOWN))
            bally++;

        // 2. Updating Positions

        // 3. Drewing
        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircle(ballx, bally, 20, {20, 160, 133, 255});

        EndDrawing();

    }
    

    CloseWindow();
    return 0;
}