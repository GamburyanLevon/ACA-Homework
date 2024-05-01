#include <iostream>
#include "bishop.h"
#include <cmath>

bishop::bishop(const std::string& position, const std::string& color) : figure(position, color)
{}
bishop::~bishop()
{
    std::cout << __func__ << std::endl;
}
bool bishop::isAttacking(const std::string& p)
{
    int currX = position[0] - 'A' + 1;
    int currY = position[1] - '1' + 1;

    int targetX = p[0] - 'A' + 1;
    int targetY = p[1] - '1' + 1;

    int dx = std::abs(targetX - currX);
    int dy = std::abs(targetY - currY);

    return dx == dy;
}
void bishop::move(const std::string& newPos)
{
    if (isAttacking(newPos))
    {
        position = newPos;
    }
}
void bishop::print()
{
    std::cout << "I am a " << color << " bishop and my position is " << position << std::endl;
}