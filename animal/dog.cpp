#include <iostream>
#include "dog.h"

Dog::Dog(const std::string& name, const int& age, const std::string& breed) : Animal(name, age), breed(breed)
{}
void Dog::print()
{
    std::cout << "My name is " << name << ", my age is " << age << " and my breed is " << breed << std::endl;
}
void Dog::voice()
{
    std::cout << "I am a Dog" << std::endl;
}
Dog::~Dog()
{
    std::cout << __func__ << std::endl;
}