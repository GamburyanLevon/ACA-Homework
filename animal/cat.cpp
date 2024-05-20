#include <iostream>
#include "cat.h"

int Cat::count = 0;

Cat::Cat(const std::string& name, const int& age,  const int& weight,  const std::string& color) : Animal(name, age, weight), color(color)
{
    count++;
}
void Cat::print()
{
    std::cout << "My name is " << name << ", my age is " << age  << ", my weight is " << weight << " and my color is " << color << std::endl;
}
void Cat::voice()
{
    std::cout << "I am a Cat" << std::endl;
}
Cat::~Cat()
{
    count--;
    std::cout << __func__ << std::endl;
}
Cat::Cat(const Cat& obj) : Animal(obj.name, obj.age, obj.weight)
{
    count++;
    color = obj.color;
}
int Cat::getCount() const
{
    return count;
}
int Cat::getAge()
{
    return age;
}
Cat::Cat(Cat&& obj) : Animal(obj.name, obj.age, obj.weight)
{
    color = obj.color;

    obj.name = " ";
    obj.age = 0;
    obj.color = " ";
    obj.weight = 0;
}