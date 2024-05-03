#include <iostream>
#include "hyperCar.h"

HyperCar::HyperCar(const std::string& model, const int& year, const int& hp,const int& price ,const int& maxSpeed, const double& acceleration, std::string specialFeatures) : SportsCar(model, year, hp, price, maxSpeed), acceleration(acceleration), specialFeatures(specialFeatures) {}

void HyperCar::print()
{
    std::cout << "Type: Hyper Car, model: " <<model << ", Year: " << year << ", Horsepowers: " << horsepower << ", price " << price  <<  ", Max Speed: " << maxSpeed << " km/h, Acceleration: " << acceleration << " seconds (0-100 km/h), Special Features: " << specialFeatures << std::endl;
}
HyperCar::~HyperCar()
{
    std::cout << __func__ << std::endl;
}
std::string HyperCar::getModel() const
{
    return model;
}
int HyperCar::getYear() const
{
    return year;
}
double HyperCar::getPrice() const
{
    return price;
}