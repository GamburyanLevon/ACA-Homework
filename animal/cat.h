#pragma once
#include "animal.h"

class Cat : public Animal {
private:
    std::string color;
    static int count;
public:
    explicit Cat(const std::string&, const int&, const int&, const  std::string&);

    virtual void print();
    Cat(const Cat&);
    Cat(Cat&&);
    int getCount() const override;
    int getAge() override;
    virtual void voice();
    ~Cat();
};