#pragma once
#include "sportsCar.h"

class HyperCar : public SportsCar 
{
protected:
    int acceleration;
    std::string specialFeatures;

public:
    HyperCar(const std::string&, const int&, const int&, const int& ,const int&, const double&, std::string);
    ~HyperCar();
    std::string getModel() const override;
    int getYear() const override;
    double getPrice() const override;
    void print() override;
};