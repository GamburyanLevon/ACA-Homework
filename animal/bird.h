#pragma once
#include "animal.h"

class Bird : public Animal {
private:
    std::string species;

public:
    Bird(const std::string&, const int&, const int&, const std::string&);

    virtual void print();

    virtual void voice();
    ~Bird();
};
