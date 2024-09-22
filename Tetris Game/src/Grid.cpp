#include "Grid.h"
#include "iostream"
#include "colors.h"

Grid::Grid()
{
    _cellSize = 30;
    Initialize();
    _colors = GetCellColors();
}

void Grid::Initialize()
{
    for(int row =0; row < _numRows; row++)
    {
        for(int col = 0; col < _numCols; col++)
        {
            grid[row][col] = 0;
        }
    }
}

void Grid::Print()
{
    for(int row =0; row < _numRows; row++)
    {
        for(int col = 0; col < _numCols; col++)
        {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw()
{
    for(int row =0; row < _numRows; row++)
    {
        for(int col = 0; col < _numCols; col++)
        {
            int cellValue = grid[row][col];

            DrawRectangle(col * _cellSize + 1, row * _cellSize + 1, _cellSize -1, _cellSize -1 , _colors[cellValue]);
        }
    }
}