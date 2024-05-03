#include <iostream>
#include "electricSedan.h"

electircSedan::electircSedan(const std::string& model, const int& year, const int& hp, const int& price, const int& numDoors, const int& electricRange) : Sedan(model, year, hp, price, numDoors), electricRange(electricRange){}

void electircSedan::print()
{
    std::cout << "Type: Electric Sedan, model: " << model << ", Year: " << year << ", Horsepowers: " << horsepower << ", price " << price << ", Number of Doors: " << numDoors << ", Electric range" << electricRange << " km" << std::endl;
}
electircSedan::~electircSedan()
{
    std::cout << __func__ << std::endl;
}
std::string electircSedan::getModel() const
{
    return model;
}
int electircSedan::getYear() const
{
    return year;
}
double electircSedan::getPrice() const
{
    return price;
}