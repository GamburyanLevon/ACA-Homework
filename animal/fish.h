#pragma once
#include "animal.h"

class Fish : public Animal {
private:
    std::string habitat;

public:
    Fish(const std::string&, const int&, const int&, const std::string&);

    virtual void print();

    virtual void voice();
    ~Fish();
};