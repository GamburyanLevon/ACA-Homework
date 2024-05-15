#include <iostream>
#include "queen.h"
#include <cmath>

queen::queen(const std::string& position, const std::string& color) : figure(position, color)
{
    symbol = 'Q';
}
queen::~queen()
{}

bool queen::isAttacking(const std::string& p, figure* board[8][8])
{
    int newRow = p[1] - '1';
    int newCol = p[0] - 'A';

    if (newRow != position[1] - '1' && newCol != position[0] - 'A' && abs(newRow - (position[1] - '1')) != abs(newCol - (position[0] - 'A'))) 
    {
        return false;
    }
    
    int startRow = position[1] - '1';
    int startCol = position[0] - 'A';

    int rowStep = (newRow > startRow) ? 1 : (newRow < startRow) ? -1 : 0;
    int colStep = (newCol > startCol) ? 1 : (newCol < startCol) ? -1 : 0;

    for (int row = startRow + rowStep, col = startCol + colStep; row != newRow || col != newCol; row += rowStep, col += colStep) 
    {
        if (board[row][col] != nullptr && board[row][col]->getSymbol() != 'K') 
        {
            return false; 
        }
    }

    return true;
}

void queen::move(const std::string& newPos)
{
    position = newPos;
}
void queen::print()
{
    std::cout << "I am a " << color << " queen and my position is " << position << std::endl;
}
char queen::getSymbol() const
{
    return symbol;
}
int queen::getRow() const
{
    int row = position[1] - '1';
    return row;
}
int queen::getCol() const
{
    int col = position[0] - 'A';
    return col;
}