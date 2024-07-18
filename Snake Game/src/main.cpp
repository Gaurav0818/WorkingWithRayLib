#include <raylib.h>
#include "Food.h"
#include "Snake.h"
#include "raymath.h"

int winHeight, winWidth;

int cellSize = 30;
int cellCount;
int offset = 00;

int main()
{
    winWidth = 900;
    winHeight = 900;

    cellCount = (winHeight - 2*offset)/30;

    InitWindow(winWidth, winHeight, "Sanke Game");
    SetTargetFPS(60);

    Snake snake = Snake();

    Food food = Food();

    int score = 0;

    bool isPause=false;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        if(!isPause)
        {
            snake.Update();
        }        
        else
        {
            DrawText("Press SPACE to continue", winWidth/6, 3*winHeight/4, 48, WHITE);

            if(IsKeyPressed(KEY_SPACE))
            {
                snake.Reset();
                isPause = false;
            }
        }

        //DrawRectangleLinesEx({10,10, (float)winWidth -20,(float) winHeight -20} ,20, WHITE);

        food.Draw();
        snake.Draw();

        if(snake.CheckCollisionWithFood(food.pos))
        {
            snake.IncreaseSize();
            score++;
            PlaySound(snake.eatSound);

            food.GenerateRandomPos();
            while(snake.ElementInDeque(food.pos))
                food.GenerateRandomPos();
        }

        if(!isPause)
            if(snake.CheckCollisionWithEdge())
                isPause = true;
        
        DrawText(TextFormat("%i", score), winWidth -100 , 50, 30, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void Food::GenerateRandomPos()
{
    float x = GetRandomValue(0, cellCount -1);
    float y = GetRandomValue(0, cellCount -1);
    pos = Vector2{x,y};
}

void Snake::Draw()
{
    for(unsigned int i=0; i<_body.size() ;i++ )
    {
        int x = _body[i].x;
        int y = _body[i].y;

        DrawRectangleRounded({offset + (float)x*cellCount , offset + (float)y*cellCount , 
                                (float)cellSize, (float)cellSize}
                                , 0.5, 6, WHITE);
    }
}

void Snake::Update()
{

    if(IsKeyPressed(KEY_UP) && _dir.y != 1 )
        _dir = {0, -1};
    
    if(IsKeyPressed(KEY_DOWN) && _dir.y != -1)
        _dir = {0, 1};
    
    if(IsKeyPressed(KEY_RIGHT) && _dir.x != -1)
        _dir = {1, 0};
    
    if(IsKeyPressed(KEY_LEFT) && _dir.x != 1)
        _dir = {-1, 0};
    
    double currentTime = GetTime();

    if(currentTime - _lastUpdateInterval < 0.2f)
        return;

    _lastUpdateInterval = currentTime;

    _body.pop_back();
    _body.push_front(Vector2Add(_body[0], _dir) );
}

bool Snake::CheckCollisionWithEdge()
{
    if(_body[0].x == cellCount || _body[0].x == -1)
    {
        PlaySound(hitSound);
        return true;
    }

    if(_body[0].y == cellCount || _body[0].y == -1)
    {
        PlaySound(hitSound);
        return true;
    }

    for(unsigned int i =1; i< _body.size(); i++)
        if(Vector2Equals(_body[0],_body[i]))
        {
            PlaySound(eatSound);
            return true;        
        }

    return false;
}

void Food::Draw()
{
    DrawCircle((float)pos.x*cellCount + (float)cellSize/2,(float)pos.y*cellCount +(float)cellSize/2, 
            (float)cellSize/3,RED);
}
