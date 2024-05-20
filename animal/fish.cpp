#include <iostream>
#include "fish.h"

int Fish::count = 0;

Fish::Fish(const std::string& name, const int& age,  const int& weight, const std::string& habitat) : Animal(name, age, weight), habitat(habitat)
{
    count++;
}

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
    count--;
    std::cout << __func__ << std::endl;
}
Fish::Fish(const Fish& obj) : Animal(obj.name, obj.age, obj.weight)
{
    count++;
    habitat = obj.habitat;
}
int Fish::getCount() const
{
    return count;
}
int Fish::getAge()
{
    return age;
}
Fish::Fish(Fish&& obj) : Animal(obj.name, obj.age, obj.weight)
{
    habitat = obj.habitat;
    
    obj.name = " ";
    obj.age = 0;
    obj.weight = 0;
    obj.habitat = " ";
}