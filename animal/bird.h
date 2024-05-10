#pragma once
#include "animal.h"

class Bird : public Animal {
private:
    std::string species;
    static int count;
public:
    Bird(const std::string&, const int&, const int&, const std::string&);
    Bird(const Bird&);
    virtual void print();
    int getCount() const override;
    virtual void voice();
    ~Bird();
};
