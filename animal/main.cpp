#include <iostream>
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "bird.h"
#include "fish.h"
#include "elephant.h"

int main()
{
    Dog *dog = new Dog("Jeko", 3, "Labrador");
    Cat *cat = new Cat("Mity", 2, "White");
    Bird *bird = new Bird("Trchun", 1, "Canary");
    Fish *fish = new Fish("Nemo", 2, "Coral reef");
    Elephant *elephant = new Elephant("Dumbo", 5, "Africa");

    Animal *animals[] = {dog, cat, bird, fish, elephant};
    for (Animal *animal : animals) {
        animal->voice();
        animal->print();
    }

    for (Animal *animal : animals) {
        delete animal;
    }

    return 0;
}