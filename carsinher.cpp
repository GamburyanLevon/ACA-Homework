#include <iostream>
#include <string>

class Car 
{
protected:
    std::string model;
    int horsepower;
    int year;
    int price;

public:
    Car(const std::string& model, const int& year, const int& hp, const int& price) : model(model), year(year), horsepower(hp), price(price) {}

    void print() 
    {
        std::cout << "model:" << model << ", Year: " << year << ", Horsepowers: " << horsepower << ", price " << price << std::endl;
    }
};

class Sedan : public Car 
{
protected:
    int numDoors;

public:
    Sedan(const std::string& model, const int year, const int& hp, const int& price, const int& numDoors) : Car(model, year, hp, price), numDoors(numDoors) {}

    void print() 
    {
        std::cout << "Type: Sedan, model: " << model << ", Year: " << year << ", Horsepowers: " << horsepower << ", price " << price << ", Number of Doors: " << numDoors << std::endl;
    }
};
class electircSedan : public Sedan
{
protected:
    int electricRange;

public:
    electircSedan(const std::string& model, const int year, const int& hp, const int& price, const int& numDoors, const int& electricRange) : Sedan(model, year, hp, price, numDoors), electricRange(electricRange){}
    void print()
    {
        std::cout << "Type: Electric Sedan, model: " << model << ", Year: " << year << ", Horsepowers: " << horsepower << ", price " << price << ", Number of Doors: " << numDoors << ", Electric range" << electricRange << " km" << std::endl;
    }
};

class Jeep : public Car {
protected:
    std::string terrainCapability;

public:
    Jeep( const std::string& model, const int year, const int& hp, const int& price, const std::string& terrainCapability) : Car(model, year, hp, price), terrainCapability(terrainCapability) {}

    void print() 
    {
        std::cout << "Type: Jeep, model: " << model << ", Year: " << year << ", Horsepowers: " << horsepower << ", price " << price  << ", Terrain Capability: " << terrainCapability << std::endl;
    }
};

class Crossover : public Jeep 
{
protected:
    std::string crossoverFeatures;

public:
    Crossover(const std::string& model, const int year, const int& hp, const int& price, const std::string& terrainCapability, const std::string& crossoverFeatures) : Jeep(model, year, hp, price, terrainCapability), crossoverFeatures(crossoverFeatures) {}

    void print()
    {
        std::cout << "Type: Crossover, model: " << model << ", Year: " << year << ", Horsepowers: " << horsepower << ", price " << price  << ", Terrain Capability: " << terrainCapability << ", Crossover Features: " << crossoverFeatures << std::endl;
    }
};

class SportsCar : public Car 
{
protected:
    int maxSpeed;

public:
    SportsCar(const std::string& model, const int year, const int& hp,const int& price ,const int& maxSpeed) : Car(model, year, hp, price), maxSpeed(maxSpeed) {}

    void print() 
    {
        std::cout << "Type: Sports Car, model: " <<model << ", Year: " << year << ", Horsepowers: " << horsepower << ", price " << price  <<  ", Max Speed: " << maxSpeed << " km/h" << std::endl;
    }
};

class HyperCar : public SportsCar 
{
protected:
    int acceleration;
    std::string specialFeatures;

public:
    HyperCar(const std::string& model, const int year, const int& hp,const int& price ,const int& maxSpeed, const double& acceleration, std::string specialFeatures) : SportsCar(model, year, hp, price, maxSpeed), acceleration(acceleration), specialFeatures(specialFeatures) {}

    void print() 
    {
        std::cout << "Type: Hyper Car, model: " <<model << ", Year: " << year << ", Horsepowers: " << horsepower << ", price " << price  <<  ", Max Speed: " << maxSpeed << " km/h, Acceleration: " << acceleration << " seconds (0-100 km/h), Special Features: " << specialFeatures << std::endl;
    }
};

int main() 
{
    electircSedan Tesla("Tesla model X", 2020, 670, 40000, 4, 500);
    Crossover Palisade("Hyudani Palisade", 2024, 291, 36000, "Crossover", "4 wheel drive");
    HyperCar Koenigsegg("Koenigsegg Jesko", 2021, 1600, 3000000, 532, 2.5, "Adjustable pedals and steering column");


    Tesla.print();
    Palisade.print();
    Koenigsegg.print();

    return 0;
}
