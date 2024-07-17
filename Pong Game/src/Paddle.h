#pragma once

#include <raylib.h>

class Paddle
{
public: 
    Paddle(int xPos , int yPos, int width, int height , 
            int speedY)
    : _xPos(xPos), _yPos(yPos), _height(height), 
    _width(width),_speedY(speedY) {}

    void Update();

    void AiUpdate(int ballY);

    bool isColliding(Vector2 center, int radius);

    void Draw();

private:
    int _xPos, _yPos, _height, _width, _speedY;
};