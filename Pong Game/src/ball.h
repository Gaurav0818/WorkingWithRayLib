#pragma once
#include <raylib.h>

class Ball
{
public:
    Ball();
    void Update();
    void Draw();
    
    Ball(int posX, int posY, float speedX, float speedY, float Radius, Color colour)
    : _posX(posX), _posY(posY), _speedX(speedX), _speedY(speedY), _radius(Radius), _colour(colour)
    {

    }

    const int GetYpos() const{return _posY;}
    const Vector2 GetCenter() const {return Vector2{(float)_posX, (float)_posY};} 
    const int GetRadius() const { return _radius;}

    void CollisionDetected();

    void ResetScore();

    int cpuScore = 0;
    int playerScore = 0;

private:
    int _posX;
    int _posY;
    int _speedX;
    int _speedY;
    int _radius;
    bool pointScored = false;
    double lastCollisionTime = 0;
    Color _colour;
};