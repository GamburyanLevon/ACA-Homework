#pragma once
#include "animal.h"

class Fish : public Animal {
private:
    std::string habitat;
    static int count;
public:
    Fish(const std::string&, const int&, const int&, const std::string&);

    virtual void print();
    Fish(const Fish&);
    Fish(Fish&&);
    int getCount() const override;
    virtual void voice();
    int getAge() override;
    ~Fish();
};