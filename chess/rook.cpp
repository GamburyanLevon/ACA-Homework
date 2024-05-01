#include <iostream>
#include "rook.h"
#include <cmath>

rook::rook(const std::string& position, const std::string& color) : figure(position, color)
{}
rook::~rook()
{
    std::cout << __func__ << std::endl;
}
bool rook::isAttacking(const std::string& p)
{
    if (p[0] == position[0] || p[1] == position[1])
    {
        return true;
    }
    
    return false;
}
void rook::move(const std::string& newPos)
{
    if (isAttacking(newPos))
    {
        position = newPos;
    }
}
void rook::print()
{
    std::cout << "I am a " << color << " rook and my position is " << position << std::endl;
}