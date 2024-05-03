#pragma once
#include <string>
#include "car.h"

class Sedan : public Car 
{
protected:
    int numDoors;

public:
    Sedan(const std::string&, const int&, const int&, const int&, const int&);
    ~Sedan();
    virtual std::string getModel() const;
    virtual int getYear() const;
    virtual double getPrice() const;
    void print() override;
};