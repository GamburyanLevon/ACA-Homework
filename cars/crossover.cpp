#include "crossover.h"
#include <iostream>

Crossover::Crossover(const std::string& model, const int& year, const int& hp, const int& price, const std::string& terrainCapability, const std::string& crossoverFeatures) : Jeep(model, year, hp, price, terrainCapability), crossoverFeatures(crossoverFeatures) {}

void Crossover::print()
{
    std::cout << "Type: Crossover, model: " << model << ", Year: " << year << ", Horsepowers: " << horsepower << ", price " << price  << ", Terrain Capability: " << terrainCapability << ", Crossover Features: " << crossoverFeatures << std::endl;
}
Crossover::~Crossover()
{
    std::cout << __func__ << std::endl;
}