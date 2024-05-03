#pragma once
#include <string>
#include "carsinterface.h"

class Car: public Carsinterface
{
protected:
    std::string model;
    int horsepower;
    int year;
    int price;

public:
    Car(const std::string&, const int&, const int&, const int&);
    virtual ~Car();
};