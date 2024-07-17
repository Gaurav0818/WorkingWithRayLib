#include "ball.h"
#include "iostream"

Ball::Ball()
{
    _posX = 100;
    _posY = 100;
    _speedX = 5;
    _speedY = 5;
    _radius = 15;
}

void Ball::Update()
{
    _posX += _speedX;
    _posY += _speedY;


    if(_posY + _radius >= GetScreenHeight() || _posY - _radius <= 0)
        _speedY *= -1;

    if(_posX + _radius >= GetScreenWidth())
    {
        cpuScore++;
        ResetScore();
    }

    if( _posX - _radius <= 0)
    {
        playerScore++;
        ResetScore();
    }
}

void Ball::ResetScore()
{
    pointScored = true;
    CollisionDetected();
}

void Ball::CollisionDetected() 
{
    if(lastCollisionTime + 0.25 < GetTime())
    {
        lastCollisionTime = GetTime();
        _speedX *= -1; 
    }
}

void Ball::Draw()
{
    if(lastCollisionTime + 0.25 > GetTime() && pointScored)
    {   
        DrawCircle(_posX, _posY, _radius, RED);
    }
    else
    {
        pointScored = false;
        DrawCircle(_posX, _posY, _radius, _colour);
    }
}