#include <iostream>
#include "animal.h"

int Animal::count = 0;

Animal::Animal(const std::string& name, const int& age, const int& weight) : name(name), age(age), weight(weight)
{
    count++;
}
Animal::~Animal()
{
    count--;
    std::cout << __func__ << std::endl;
}
Animal::Animal(const Animal& obj)
{
    count++;
    name = obj.name;
    age = obj.age;
    weight = obj.weight;
}