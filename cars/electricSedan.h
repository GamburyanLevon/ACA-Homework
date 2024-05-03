#pragma once
#include "sedan.h"

class electircSedan : public Sedan
{
protected:
    int electricRange;

public:
    electircSedan(const std::string&, const int&, const int&, const int&, const int&, const int&);
    ~electircSedan();
    virtual std::string getModel() const;
    virtual int getYear() const;
    virtual double getPrice() const;
    void print() override;
};
