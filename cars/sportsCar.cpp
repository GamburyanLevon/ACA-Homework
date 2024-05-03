#include <iostream>
#include "sportsCar.h"

SportsCar::SportsCar(const std::string& model, const int& year, const int& hp,const int& price ,const int& maxSpeed) : Car(model, year, hp, price), maxSpeed(maxSpeed) {}

void SportsCar::print()
{
    std::cout << "Type: Sports Car, model: " <<model << ", Year: " << year << ", Horsepowers: " << horsepower << ", price " << price  <<  ", Max Speed: " << maxSpeed << " km/h" << std::endl;
}
SportsCar::~SportsCar()
{
    std::cout << __func__ << std::endl;
}
std::string SportsCar::getModel() const
{
    return model;
}
int SportsCar::getYear() const
{
    return year;
}
double SportsCar::getPrice() const
{
    return price;
}