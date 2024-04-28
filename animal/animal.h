#pragma once
#include <string>

class Animal {
protected:
    std::string name;
    int age;

public:
    Animal(const std::string&, const int&);

    virtual ~Animal();

    virtual void print();

    virtual void voice();
};