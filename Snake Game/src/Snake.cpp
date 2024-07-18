#include"Snake.h"

#include "raymath.h"

bool Snake::CheckCollisionWithFood(Vector2 pos)
{
    if(Vector2Equals(_body[0], pos))
        return true;
    else 
        return false;
}

bool Snake::ElementInDeque(Vector2 pos)
{
    for(unsigned int i =0; i< _body.size(); i++)
            if(Vector2Equals(pos,{_body[i].x, _body[i].y}))
                return true;

    return false;
}

void Snake::IncreaseSize()
{
    _body.push_back({_body[_body.size() -1].x,_body[_body.size() -1].y});
}