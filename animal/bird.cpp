#include <iostream>
#include "bird.h"

Bird::Bird(const std::string& name, const int& age, const std::string& species) : Animal(name, age), species(species)
{}

void Bird::print()
{
    std::cout << "My name is " << name << ", my age is " << age << " and my species is " << species << std::endl;
}
void Bird::voice()
{
    std::cout << "I am a Bird" << std::endl;
}
Bird::~Bird()
{
    std::cout << __func__ << std::endl;
}