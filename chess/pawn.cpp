#include <iostream>
#include "pawn.h"
#include <cmath>

pawn::pawn(const std::string& position, const std::string& color) : figure(position, color)
{
    symbol = 'P';
}
pawn::~pawn()
{

}
bool pawn::isAttacking(const std::string& p, figure* board[8][8])
{
    int newRow = p[1] - '1';
    int newCol = p[0] - 'A';

    int startRow = position[1] - '1';
    int startCol = position[0] - 'A';

    int direction = (color == "White") ? 1 : -1;
    
    
    if (newCol == startCol) 
    {
        
        if (newRow == startRow + direction && board[newRow][newCol] == nullptr) 
        {
            
            return true;
        }
        if (startRow == (color == "white" ? 1 : 6) && newRow == startRow + 2 * direction && board[startRow + direction][newCol] == nullptr && board[newRow][newCol] == nullptr) 
        {
            return true;
        }
    }
    
    else if (abs(newCol - startCol) == 1 && newRow == startRow + direction) 
    {
        if (board[newRow][newCol] != nullptr) 
        {
            return true;
        }
    }
    return false;
}
void pawn::move(const std::string& newPos)
{
    position = newPos;   
}
void pawn::print()
{
    std::cout << "I am a " << color << " pawn and my position is " << position << std::endl;
}
char pawn::getSymbol() const
{
    return symbol;
}
int pawn::getRow() const
{
    int row = position[1] - '1';
    return row;
}
int pawn::getCol() const
{
    int col = position[0] - 'A';
    return col;
}
std::string pawn::getColor() const
{
    return color;
}