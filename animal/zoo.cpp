#include "zoo.h"
#include <iostream>

zoo* zoo::instance = nullptr;

zoo::zoo() : count(0)
{}


void zoo::registerAnimal(Animal& animal)
{
    if (count < 20) 
    {
        animals[count++] = &animal;
    } 
    else 
    {
        std::cout << "Zoo is at maximum capacity. Cannot register more animals" << std::endl;
    }
}
void zoo::removeTheLastAnimal()
{
    if (count > 0) 
    {
        --count;
    } 
    else 
    {
        std::cout << "No animals to remove" << std::endl;
    }
}
void zoo::print()
{
    std::cout << "Animals in the zoo " << count << ":"<< std::endl;
    for (int i = 0; i < count; ++i) 
    {
        animals[i]->voice(); 
    }
}
zoo* zoo::getInstance() 
{
    if (!instance) 
    {
        instance = new zoo();
    }
    return instance;
}