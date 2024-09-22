#pragma once

#include <raylib.h>
#include <vector>
#include <map>
#include "Position.h"
#include "colors.h"


class Block
{

public:
    Block();

    void Draw();

    ~Block() = default;
    int id;
    std::map<int, std::vector<Position>> cells;

private:

    int _cellSize;
    int _rotationState;
    std::vector<Color> _colors;
};