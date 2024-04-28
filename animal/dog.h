#pragma once
#include "animal.h"

class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(const std::string&, const int&, const std::string&);

    virtual void print();

    virtual void voice();
    ~Dog();
};
