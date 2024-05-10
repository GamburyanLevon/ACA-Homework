#include <iostream>
#include "elephant.h"

int Elephant::count = 0;

Elephant::Elephant(const std::string& name, const int& age,  const int& weight, const std::string& location) : Animal(name, age, weight), location(location)
{
    count++;
}

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
    count--;
    std::cout << __func__ << std::endl;
}
Elephant::Elephant(const Elephant& obj) : Animal(obj.name, obj.age, obj.weight)
{
    count++;
    location = obj.location;
}
int Elephant::getCount() const
{
    return count;
}