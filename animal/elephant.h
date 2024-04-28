#pragma once
#include "animal.h"

class Elephant : public Animal {
private:
    std::string location;

public:
    Elephant(const std::string&,const int& age,const std::string& location);

    virtual void print();

    virtual void voice();
    ~Elephant();
};
