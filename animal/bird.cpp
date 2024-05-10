#include <iostream>
#include "bird.h"

int Bird::count = 0;

Bird::Bird(const std::string& name, const int& age,  const int& weight,  const std::string& species) : Animal(name, age, weight), species(species)
{
    count++;
}

void Bird::print()
{
    std::cout << "My name is " << name << ", my age is " << age << ", my weight is " << weight  << " and my species is " << species << std::endl;
}
void Bird::voice()
{
    std::cout << "I am a Bird" << std::endl;
}
Bird::~Bird()
{
    count--;
    std::cout << __func__ << std::endl;
}
Bird::Bird(const Bird& obj) : Animal(obj.name, obj.age, obj.weight)
{
    count++;
    species = obj.species;
}
int Bird::getCount() const
{
    return count;
}