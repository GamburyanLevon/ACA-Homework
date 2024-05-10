#pragma once
#include "animal.h"

class Cat : public Animal {
private:
    std::string color;
    static int count;
public:
    Cat(const std::string&, const int&, const int&, const  std::string&);

    virtual void print();
    Cat(const Cat&);
    int getCount() const override;
    virtual void voice();
    ~Cat();
};