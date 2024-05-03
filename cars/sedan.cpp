#include <iostream>
#include "sedan.h"

Sedan::Sedan(const std::string& model, const int& year, const int& hp, const int& price, const int& numDoors) : Car(model, year, hp, price), numDoors(numDoors) {}

void Sedan::print()
{
    std::cout << "Type: Sedan, model: " << model << ", Year: " << year << ", Horsepowers: " << horsepower << ", price " << price << ", Number of Doors: " << numDoors << std::endl;
}
Sedan::~Sedan()
{
    std::cout << __func__ << std::endl;
}
std::string Sedan::getModel() const
{
    return model;
}
int Sedan::getYear() const
{
    return year;
}
double Sedan::getPrice() const
{
    return price;
}