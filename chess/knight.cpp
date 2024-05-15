#include <iostream>
#include "knight.h"
#include <cmath>

knight::knight(const std::string& position, const std::string& color) : figure(position, color)
{
    symbol = 'N';
}
knight::~knight()
{

}
bool knight::isAttacking(const std::string& p, figure* board[8][8])
{
    int currX = position[0] - 'A' + 1;
    int currY = position[1] - '1' + 1;

    int targetX = p[0] - 'A' + 1;
    int targetY = p[1] - '1' + 1;

    int dx = std::abs(targetX - currX);
    int dy = std::abs(targetY - currY);

    if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2))
    {
        return true;
    }

    return false;
}
void knight::move(const std::string& newPos)
{
    position = newPos;
}
void knight::print()
{
    std::cout << "I am a " << color << " knight and my position is " << position << std::endl;
}
char knight::getSymbol() const
{
    return symbol;
}
int knight::getRow() const
{
    int row = position[1] - '1';
    return row;
}
int knight::getCol() const
{
    int col = position[0] - 'A';
    return col;
}