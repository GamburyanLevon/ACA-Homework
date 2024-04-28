#include <iostream>
#include "cat.h"

Cat::Cat(const std::string& name, const int& age, const std::string& color) : Animal(name, age), color(color)
{}
void Cat::print()
{
    std::cout << "My name is " << name << ", my age is " << age << " and my color is " << color << std::endl;
}
void Cat::voice()
{
    std::cout << "I am a Cat" << std::endl;
}
Cat::~Cat()
{
    std::cout << __func__ << std::endl;
}