#pragma once
#include "animal.h"

class Elephant : public Animal {
private:
    std::string location;

public:
    Elephant(const std::string&,const int& age,  const int&, const std::string&);

    virtual void print();

    virtual void voice();
    ~Elephant();
};
