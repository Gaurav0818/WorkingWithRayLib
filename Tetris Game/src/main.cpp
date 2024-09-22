#include <raylib.h>
#include "Grid.h"
#include "Tiles.h"

int winHeight, winWidth;

int main()
{
    winWidth = 600;
    winHeight = 900;

    InitWindow(winWidth, winHeight, "Tetris Game");
    SetTargetFPS(60);

    Grid grid;

    grid.Print();

    LBlock block = LBlock();

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        grid.Draw();
        block.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}