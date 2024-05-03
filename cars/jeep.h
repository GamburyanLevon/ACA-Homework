#pragma once
#include "car.h"

class Jeep : public Car {
protected:
    std::string terrainCapability;

public:
    Jeep( const std::string&, const int&, const int& , const int&, const std::string&);
    ~Jeep();
    virtual std::string getModel() const;
    virtual int getYear() const;
    virtual double getPrice() const;
    void print() override;
};