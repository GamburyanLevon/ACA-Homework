#include <iostream>
#include "dog.h"

Dog::Dog(const std::string& name, const int& age,  const int& weight, const std::string& breed) : Animal(name, age, weight), breed(breed)
{}
void Dog::print()
{
    std::cout << "My name is " << name << ", my age is " << age << ", my weight is " << weight << " and my breed is " << breed << std::endl;
}
void Dog::voice()
{
    std::cout << "I am a Dog" << std::endl;
}
Dog::~Dog()
{
    std::cout << __func__ << std::endl;
}