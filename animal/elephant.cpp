#include <iostream>
#include "elephant.h"

Elephant::Elephant(const std::string& name, const int& age,  const int& weight, const std::string& location) : Animal(name, age, weight), location(location)
{}

void Elephant::print()
{
    std::cout << "My name is " << name << ", my age is " << age << ", my weight is " << weight  << " and my location is " << location << std::endl;
}
void Elephant::voice()
{
    std::cout << "I am a Elephant" << std::endl;
}
Elephant::~Elephant()
{
    std::cout << __func__ << std::endl;
}