#include <iostream>
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "bird.h"
#include "fish.h"
#include "elephant.h"
#include "zoo.h"

int main()
{
    zoo* myZoo = zoo::getInstance();

    Dog dog("Jeko", 3, 15, "Labrador");
    Cat cat ("Mity", 2, 3, "White");
    Bird bird("Trchun", 1, 1, "Canary");
    Fish fish("Nemo", 2, 2, "Coral reef");
    Elephant elephant("Dumbo", 5, 1000, "Africa");

    myZoo->registerAnimal(dog);
    myZoo->registerAnimal(cat);
    myZoo->registerAnimal(fish);
    myZoo->registerAnimal(bird);
    myZoo->registerAnimal(elephant);

    myZoo->print();

    myZoo->removeTheLastAnimal();

    myZoo->print();

    zoo* hiszoo = zoo::getInstance();

    return 0;
}