#include "car.h"
#include <iostream>

Car::Car(const std::string& model, const int& year, const int& hp, const int& price) : model(model), year(year), horsepower(hp), price(price) {}

Car::~Car()
{
    std::cout << __func__ << std::endl;
}
