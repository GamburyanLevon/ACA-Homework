#include <iostream>
#include "fish.h"

Fish::Fish(const std::string& name, const int& age,  const int& weight, const std::string& habitat) : Animal(name, age, weight), habitat(habitat)
{}

void Fish::print()
{
    std::cout << "My name is " << name << ", my age is " << age << ", my weight is " << weight  << " and my habitat is " << habitat << std::endl;
}
void Fish::voice()
{
    std::cout << "I am a Fish" << std::endl;
}
Fish::~Fish()
{
    std::cout << __func__ << std::endl;
}