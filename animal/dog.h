#pragma once
#include "animal.h"

class Dog : public Animal {
private:
    std::string breed;
    static int count;
public:
    explicit Dog(const std::string&, const int&, const int&, const std::string&);

    virtual void print();
    Dog(const Dog&);
    Dog(Dog&&);
    int getCount() const override;
    virtual void voice();
    int getAge() override;
    ~Dog();
};
