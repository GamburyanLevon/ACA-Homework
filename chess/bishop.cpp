#include <iostream>
#include "bishop.h"
#include <cmath>

bishop::bishop(const std::string& position, const std::string& color) : figure(position, color)
{
    symbol = 'B';
}
bishop::~bishop()
{

}
bool bishop::isAttacking(const std::string& p, figure* board[8][8])
{
    int newRow = p[1] - '1';
    int newCol = p[0] - 'A';

    if (abs(newRow - (position[1] - '1')) != abs(newCol - (position[0] - 'A'))) 
    {   
        
        return false; 
    }

    int rowStep = (newRow > (position[1] - '1')) ? 1 : -1;
    int colStep = (newCol > (position[0] - 'A')) ? 1 : -1;

    int row = position[1] - '1' + rowStep;
    int col = position[0] - 'A' + colStep;
    while (row != newRow && col != newCol) 
    {
        if (board[row][col] != nullptr) 
        {
            return false;
        }
        row += rowStep;
        col += colStep;
    }
    return true; 
}
void bishop::move(const std::string& newPos)
{
    position = newPos;
}

void bishop::print()
{
    std::cout << "I am a " << color << " bishop and my position is " << position << std::endl;
}
char bishop::getSymbol() const
{
    return symbol;
}
int bishop::getRow() const
{
    int row = position[1] - '1';
    return row;
}
int bishop::getCol() const
{
    int col = position[0] - 'A';
    return col;
}
std::string bishop::getColor() const
{
    return color;
}