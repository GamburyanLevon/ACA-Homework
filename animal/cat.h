#pragma once
#include "animal.h"

class Cat : public Animal {
private:
    std::string color;

public:
    Cat(const std::string&, const int&, const  std::string&);

    virtual void print();

    virtual void voice();
    ~Cat();
};