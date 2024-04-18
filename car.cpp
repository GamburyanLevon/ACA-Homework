#include <iostream>
#include <string>

class Car {
public:
    Car(int horsepowers, const std::string& mod, int y, float pr, int mil)
        {
            horsepower = horsepowers;
            model = mod;
            year = y;
            price = pr;
            mileage = mil;
        }

    void printDetails() const {
        std::cout << "Horsepower: " << horsepower << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Mileage: " << mileage << " miles" << std::endl;
    }

private:
    int horsepower;
    std::string model;
    int year;
    float price;
    int mileage;
};

int main() {
    Car car(500, "Camry", 2022, 25000, 15000);
    car.printDetails();
    return 0;
}
