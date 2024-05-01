#include <iostream>
#include "pawn.h"
#include <cmath>

pawn::pawn(const std::string& position, const std::string& color) : figure(position, color)
{}
pawn::~pawn()
{
    std::cout << __func__ << std::endl;
}
bool pawn::isAttacking(const std::string& p)
{
    int currX = position[0] - 'A' + 1;
    int currY = position[1] - '1' + 1;

    int targetX = p[0] - 'A' + 1;
    int targetY = p[1] - '1' + 1;

    int dx = targetX - currX;
    int dy = targetY - currY;

    int direction = (color=="white") ? 1 : -1;
   
    if(targetX == currX && targetY == currY + direction)
    {
        return true;
    }
    return false;
}
void pawn::move(const std::string& newPos)
{
    if (isAttacking(newPos))
    {
        position = newPos;
    }
}
void pawn::print()
{
    std::cout << "I am a " << color << " pawn and my position is " << position << std::endl;
}