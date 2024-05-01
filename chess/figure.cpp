#include <iostream>
#include "figure.h"

figure::figure(const std::string& position, const std::string& color) : position(position), color(color) 
{}
figure::~figure()
{
    std::cout << __func__ << std::endl;
}
