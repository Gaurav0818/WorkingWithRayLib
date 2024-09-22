#include "Block.h"

Block::Block()
{
    _cellSize = 30;
    _rotationState = 0;
    _colors = GetCellColors();
}

void Block::Draw()
{
    std::vector<Position> tiles = cells[_rotationState];
    for( Position item : tiles)
    {
        DrawRectangle(item.col * _cellSize + 1, item.row * _cellSize + 1, _cellSize - 1, _cellSize -1, _colors[id]);
    }
}