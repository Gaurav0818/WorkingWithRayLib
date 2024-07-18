#pragma once
#include <raylib.h>
//#include "Core.h"

class Food
{
public:
    Food()
    {
        GenerateRandomPos();
    }

    ~Food() = default;

    void Draw();
    Vector2 pos;

    void GenerateRandomPos();

};

