#pragma once
#include "jeep.h"

class Crossover : public Jeep 
{
protected:
    std::string crossoverFeatures;

public:
    Crossover(const std::string&, const int&, const int&, const int&, const std::string&, const std::string&);
    ~Crossover();
    virtual std::string getModel() const;
    virtual int getYear() const;
    virtual double getPrice() const;
    void print() override;
};