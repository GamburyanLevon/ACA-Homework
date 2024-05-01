#include <iostream>
#include "queen.h"
#include <cmath>

queen::queen(const std::string& position, const std::string& color) : figure(position, color)
{}
queen::~queen()
{
    std::cout << __func__ << std::endl;
}
bool queen::isAttacking(const std::string& p)
{
    int currX = position[0] - 'A' + 1;
    int currY = position[1] - '1' + 1;

    int targetX = p[0] - 'A' + 1;
    int targetY = p[1] - '1' + 1;

    int dx = std::abs(targetX - currX);
    int dy = std::abs(targetY - currY);

    if (currX == targetX || currY == targetY || dx == dy)
    {
        return true;
    }
    return false;
}
void queen::move(const std::string& newPos)
{
    if (isAttacking(newPos))
    {
        position = newPos;
    }
}
void queen::print()
{
    std::cout << "I am a " << color << " queen and my position is " << position << std::endl;
}