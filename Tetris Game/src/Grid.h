#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
public:
    Grid();
    ~Grid() = default;

    void Initialize();

    void Print();

    void Draw();

private:

    const static int _numRows = 30;
    const static int _numCols = 10;
    int _cellSize;
    std::vector<Color> _colors;

public:
    int grid[_numRows][_numCols];


};