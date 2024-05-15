#include <iostream>
#include "king.h"
#include <cmath>

king::king(const std::string& position, const std::string& color) : figure(position, color)
{
    symbol = 'K';
}
king::~king()
{

}
bool king::isAttacking(const std::string& p, figure* board[8][8])
{
    int newRow = p[1] - '1';
    int newCol = p[0] - 'A';

    int startRow = position[1] - '1';
    int startCol = position[0] - 'A';

    int rowDiff = abs(newRow - startRow);
    int colDiff = abs(newCol - startCol);
    if ((rowDiff > 1 || colDiff > 1)) 
    {
        return false;
    }

    return true; 
}
void king::move(const std::string& newPos)
{
    
    position = newPos;
}

void king::print()
{
    std::cout << "I am a " << color << " bishop and my position is " << position << std::endl;
}
char king::getSymbol() const
{
    return symbol;
}
int king::getRow() const
{
    int row = position[1] - '1';
    return row;
}
int king::getCol() const
{
    int col = position[0] - 'A';
    return col;
}
std::string king::getColor() const
{
    return color;
}