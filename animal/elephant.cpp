#include <iostream>
#include "elephant.h"

Elephant::Elephant(const std::string& name, const int& age, const std::string& location) : Animal(name, age), location(location)
{}

void Elephant::print()
{
    std::cout << "My name is " << name << ", my age is " << age << " and my location is " << location << std::endl;
}
void Elephant::voice()
{
    std::cout << "I am a Elephant" << std::endl;
}
Elephant::~Elephant()
{
    std::cout << __func__ << std::endl;
}