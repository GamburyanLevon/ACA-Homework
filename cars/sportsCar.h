#pragma once
#include "car.h"

class SportsCar : public Car 
{
protected:
    int maxSpeed;

public:
    SportsCar(const std::string&, const int&, const int& ,const int&,const int&);
    ~SportsCar();
    std::string getModel() const override;
    int getYear() const override;
    double getPrice() const override;
    void print() override;
};