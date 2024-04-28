#include <iostream>
#include "animal.h"

Animal::Animal(const std::string& name, const int& age) : name(name), age(age)
{}
Animal::~Animal()
{
    std::cout << __func__ << std::endl;
}
void Animal::print()
{
    std::cout << "My name is " << name << " and my age is " << age << std::endl;
}
void Animal::voice()
{
    std::cout << "I am an Aninaml" << std::endl;
}