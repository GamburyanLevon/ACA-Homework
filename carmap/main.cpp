#include <iostream>
#include <string>
#include <unordered_map>

class Car
{
public:
    std::string model;
    int year;
    int speed;

    Car(const std::string &model, int year, int speed)
        : model(model), year(year), speed(speed) {}

    bool operator==(const Car &other) const
    {
        return speed == other.speed && model == other.model && year == other.year;
    }
    bool operator<(const Car &other) const
    {
        return speed < other.speed && year < other.year;
    }
};

struct CarHash
{
    std::size_t operator()(const Car &car) const
    {
        std::size_t h1 = std::hash<int>()(car.speed);
        std::size_t h2 = std::hash<std::string>()(car.model);
        std::size_t h3 = std::hash<int>()(car.year);
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

int main()
{
    std::unordered_map<Car, std::string, CarHash> carOwners;

    Car car1("Toyota", 2018, 300);
    Car car2("Honda", 2019, 250);
    Car car3("Tesla", 2020, 400);

    carOwners[car1] = "Alice";
    carOwners[car2] = "Bob";
    carOwners[car3] = "Charlie";

    for (const auto &pair : carOwners)
    {
        const Car &car = pair.first;
        const std::string &owner = pair.second;
        std::cout << owner << " owns a " << car.year << " " << car.speed << " " << car.model << std::endl;
    }

    return 0;
}
