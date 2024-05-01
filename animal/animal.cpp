#include <iostream>
#include "animal.h"

Animal::Animal(const std::string& name, const int& age, const int& weight) : name(name), age(age), weight(weight)
{}
Animal::~Animal()
{
    std::cout << __func__ << std::endl;
}
