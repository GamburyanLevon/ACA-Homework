#include <iostream>
#include <string>



class Car {
protected:
    std::string model;
    int horsepower;
    int year;
    int price;

public:
    Car(const std::string& model, const int& year, const int& hp, const int& price) : model(model), year(year), horsepower(hp), price(price) {}

    void print() {
        std::cout << "model:" << model << ", Year: " << year << ", Horsepowers: " << horsepower << ", price " << price << std::endl;
    }
};

class Sedan : public Car {
protected:
    int numDoors;

public:
    Sedan(const std::string& model, const int year, const int& hp, const int& price, const int& numDoors) : Car(model, year, hp, price), numDoors(numDoors) {}

    void print() {
        std::cout << "Type: Sedan, model: " << model << ", Year: " << year << ", Horsepowers: " << horsepower << ", price " << price << ", Number of Doors: " << numDoors << std::endl;
    }
};

class Jeep : public Car {
protected:
    std::string terrainCapability;

public:
    Jeep( const std::string& model, const int year, const int& hp, const int& price, const std::string& terrainCapability) : Car(model, year, hp, price), terrainCapability(terrainCapability) {}

    void print() {
        std::cout << "Type: Jeep, model: " << model << ", Year: " << year << ", Horsepowers: " << horsepower << ", price " << price  << ", Terrain Capability: " << terrainCapability << std::endl;
    }
};

class SportsCar : public Car {
protected:
    int maxSpeed;

public:
    SportsCar(const std::string& model, const int year, const int& hp,const int& price ,const int& maxSpeed) : Car(model, year, hp, price), maxSpeed(maxSpeed) {}

    void print() {
        std::cout << "Type: Sports Car, model: " <<model << ", Year: " << year << ", Horsepowers: " << horsepower << ", price " << price  <<  ", Max Speed: " << maxSpeed << " km/h" << std::endl;
    }
};

int main() {
    Sedan sedan("BMW", 2022, 500, 50000, 4);
    Jeep Jeep("Jeep", 2023, 150, 30000,"off-road");
    SportsCar sportsCar("Ferrari", 2024, 800, 200000, 400);

    sedan.print();
    Jeep.print();
    sportsCar.print();

    return 0;
}
