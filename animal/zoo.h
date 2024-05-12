#pragma once
#include "animal.h"

class zoo
{
private:
    Animal* animals[20];
    int count;
    static zoo* instance;
    zoo();
public:
    ~zoo();
    static zoo* getInstance();
    void registerAnimal(Animal&);
    void removeTheLastAnimal();
    void print();
    static int getount();
};