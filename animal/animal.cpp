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
bool Animal::operator==(const Animal& obj) const
{
    return this->age == obj.age;
}

bool Animal::operator>(const Animal& obj) const
{
    return this->age > obj.age;
}
bool Animal::operator<(const Animal& obj) const
{
    return this->age < obj.age;
}
Animal::Animal(Animal&& other) noexcept : name(std::move(other.name)), age(other.age) 
{
    other.age = 0;
}
Animal& Animal::operator=(Animal&& obj) noexcept 
{
    if (this != &obj) 
    {
        name = std::move(obj.name);
        age = obj.age;
        obj.age = 0;
    }
    return *this;
}