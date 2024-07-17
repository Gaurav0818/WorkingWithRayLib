#include "Paddle.h"
#include <raylib.h>

void Paddle::Update()
{

    if(IsKeyDown(KEY_UP))
    {
        _yPos = _yPos - _speedY;
    }
    
    if(IsKeyDown(KEY_DOWN))
    {
        _yPos = _yPos + _speedY;
    }

    if(_yPos<=0)
    {
        _yPos=0;
    }

    if(_yPos + _height >= GetScreenHeight())
    {
        _yPos = GetScreenHeight() - _height;
    }

}

void Paddle::AiUpdate(int ballY)
{
    if( _yPos + _height/2 > ballY)
        _yPos = _yPos - _speedY;
    else
        _yPos = _yPos + _speedY;
    

    if(_yPos<=0)
    {
        _yPos=0;
    }

    if(_yPos + _height >= GetScreenHeight())
    {
        _yPos = GetScreenHeight() - _height;
    }

}

bool Paddle::isColliding(Vector2 center, int radius)
{
    if(CheckCollisionCircleRec(center, radius, 
        Rectangle{ (float)_xPos, (float)_yPos, (float)_width, (float)_height}))
        return true;
    else
        return false;
}



void Paddle::Draw()
{
    DrawRectangle(_xPos, _yPos, _width, _height, WHITE);
}