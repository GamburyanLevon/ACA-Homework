#include <iostream>
#include <string>
#include <vector>

class Manufacturer {
public:

    Manufacturer(const std::string& m, const std::string& c) : model(m), country(c) {}

    std::string getModel() const 
    {
        return model;
    }

    std::string getCountry() const 
    {
        return country;
    }


    void print() const 
    {
        std::cout << "Manufacturer: " << model << " | Country: " << country << std::endl;
    }
private:
    std::string model;
    std::string country;

};
class Engine {
public:

    Engine(int hp, const std::string& tp) : horsePower(hp), typeFuel(tp)
    {}
    std::string getTypeFuel() const
    {
        return typeFuel;
    }
    int getHorsePower() const 
    {
        return horsePower;
    }
    void print() const
    {
        std::cout << "Horsepower: " << horsePower << std::endl;
        std::cout << "Type of fuel: " << typeFuel << std::endl;
    }
private:
    int horsePower;
    std::string typeFuel;
};

class Car
{
public:
    Car(const std::string& manuName, const std::string& manuCountry, int y, const std::string &reg, int hp, const std::string& tp, float pr, int f ) : manu(manuName, manuCountry) , engine(hp, tp), year(y), price(pr), regNumber(reg), numFine(f)
    {}

    void print() const
    {
        manu.print();
        std::cout << "Cars registration number: " << regNumber << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Price: " << price << std::endl;
        engine.print();
    }
    std::string getregNumber() const
    {
        return regNumber;
    }
    int& getnumFine()
    {
        return numFine;
    }
    int getnumFine() const
    {
        return numFine;
    }

private:
    int horsepower;
    int year;
    float price;
    std::string regNumber;
    int numFine;
    Manufacturer manu;
    Engine engine;
};

class Parking
{
public:
    Parking(int Max) : maxCapacity(Max)
    {
        cars = new Car *[maxCapacity];
        for (int i = 0; i < maxCapacity; i++)
        {
            cars[i] = nullptr;
        }
    }
    ~Parking()
    {
        for (int i = 0; i < numCars; ++i)
        {
            delete cars[i];
        }
        delete[] cars;
    }
    void parkCar(const Car &car)
    {        
        if (car.getnumFine())
        {
            std::cout << "You have fine, you cannot park your car here" << std::endl;
            return;
        }
        
        if (numCars < maxCapacity)
        {
            cars[numCars] = new Car(car);
            std::cout << "Car parked: ";
            car.print();
            numCars++;
        }
        else
        {
            std::cout << "Parking is full. Cannot park car." << std::endl;
        }
    }

    void removeCar(const std::string &regNumber, int h, int m)
    {
        for (int i = 0; i < numCars; ++i)
        {
            if (cars[i]->getregNumber() == regNumber)
            {
                if (m <= h*payPerHour)
                {
                    std::cout << "You dont have enough money. You get a fine for this." << std::endl;
                    cars[i]->getnumFine()++;
                }
                std::cout << "Car removed: ";
                cars[i]->print();
                delete cars[i];
                cars[i] = nullptr;
                for (int j = i; j < numCars - 1; ++j)
                {
                    cars[j] = cars[j + 1];
                }
                cars[numCars - 1] = nullptr;
                numCars--;
                return;
            }
        }
        std::cout << "Car with registration number " << regNumber << " not found in parking." << std::endl;
    }

    bool isCarParked(const std::string &regNumber) const
    {
        for (int i = 0; i < numCars; ++i)
        {
            if (cars[i]->getregNumber() == regNumber)
            {
                return true;
            }
        }
        return false;
    }
    int getFreeFields()
    {
        return maxCapacity-numCars;
    }
    int getNumParkedCars() const
    {
        return numCars;
    }

    void displayCars() const
    {
        if (numCars == 0)
        {
            std::cout << "No cars parked in the parking lot." << std::endl;
            return;
        }

        std::cout << "Cars in the parking lot:\n";
        for (int i = 0; i < numCars; ++i)
        {
            cars[i]->print();
        }
    }
private:
    int maxCapacity;
    Car **cars;
    int numCars = 0;
    const int payPerHour = 10;
};


int main()
{
    Car car1("BMW", "Germany", 2020, "33ZZ333", 600,"Benzin", 30000, 1);
    Car car2("Mercedes", "Germany", 2021, "11II111", 500, "Gaz" , 25000, 0);

    Parking parkingLot(10);

    parkingLot.parkCar(car1);
    parkingLot.parkCar(car2);

    parkingLot.removeCar(car2.getregNumber(), 3, 60);
    std::cout << parkingLot.getNumParkedCars() << std::endl;

    return 0;
}
