#pragma once
#include <string>

class Car 
{
protected:
    std::string model;
    int horsepower;
    int year;
    int price;

public:
    Car(const std::string&, const int&, const int&, const int&);
    virtual ~Car();
    virtual std::string getModel() const = 0;
    virtual int getYear() const = 0;
    virtual double getPrice() const = 0;
    virtual void print() = 0; 
};