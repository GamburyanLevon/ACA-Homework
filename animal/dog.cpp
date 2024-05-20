#include <iostream>
#include "dog.h"

int Dog::count = 0;

Dog::Dog(const std::string& name, const int& age,  const int& weight, const std::string& breed) : Animal(name, age, weight), breed(breed)
{
    count++;
}
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
    count--;
    std::cout << __func__ << std::endl;
}
Dog::Dog(const Dog& obj) : Animal(obj.name, obj.age, obj.weight)
{
    count++;
    breed = obj.breed;
}
int Dog::getCount() const
{
    return count;
}
int Dog::getAge()
{
    return age;
}
Dog::Dog(Dog&& obj) : Animal(obj.name, obj.age, obj.weight)
{
    breed = obj.breed;
    
    obj.name = " ";
    obj.age = 0;
    obj.weight = 0;
    obj.breed = " ";
}