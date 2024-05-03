#include <iostream>
#include "jeep.h"

Jeep::Jeep( const std::string& model, const int& year, const int& hp, const int& price, const std::string& terrainCapability) : Car(model, year, hp, price), terrainCapability(terrainCapability) {}

void Jeep::print()
{
    std::cout << "Type: Jeep, model: " << model << ", Year: " << year << ", Horsepowers: " << horsepower << ", price " << price  << ", Terrain Capability: " << terrainCapability << std::endl;
}
Jeep::~Jeep()
{
    std::cout << __func__ << std::endl;
}
std::string Jeep::getModel() const
{
    return model;
}
int Jeep::getYear() const
{
    return year;
}
double Jeep::getPrice() const
{
    return price;
}