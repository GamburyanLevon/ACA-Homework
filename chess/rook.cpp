#include <iostream>
#include "rook.h"
#include <cmath>

rook::rook(const std::string& position, const std::string& color) : figure(position, color)
{
    symbol = 'R';
}
rook::~rook()
{

}
bool rook::isAttacking(const std::string& p, figure* board[8][8])
{
    int newRow = p[1] - '1';
    int newCol = p[0] - 'A';

    if (p[0] != position[0] && p[1] != position[1]) 
    {
        return false;
    }

    int start, end;
    if (p[0] == position[0]) 
    {
        start = (newCol < (position[1]-'1')) ? newCol : (position[1] - '1');
        end = (newCol > (position[1]-'1')) ? newCol : (position[1] - '1');
    } 
    else 
    {
        start = (newRow < (position[0]-'A')) ? newRow : (position[0] - 'A');
        end = (newRow > (position[0]-'A')) ? newRow : (position[0] - 'A');
    }

    for (int i = start + 1; i < end; ++i) 
    {
        if ((board[position[1] - '1'][i] != nullptr) ||
            (board[i][position[0] - 'A'] != nullptr)) 
        {
            return false; 
        }
    }
    return true;
}
void rook::move(const std::string& newPos)
{
    position = newPos;
}
void rook::print()
{
    std::cout << "I am a " << color << " rook and my position is " << position << std::endl;
}
char rook::getSymbol() const
{
    return symbol;
}
int rook::getRow() const
{
    int row = position[1] - '1';
    return row;
}
int rook::getCol() const
{
    int col = position[0] - 'A';
    return col;
}
std::string rook::getColor() const
{
    return color;
}