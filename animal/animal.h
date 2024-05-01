#pragma once
#include <string>

class Animal {
protected:
    std::string name;
    int age;
    int weight;

public:
    Animal(const std::string&, const int& , const int&);

    virtual ~Animal();

    virtual void print() = 0;

    virtual void voice() = 0;
};