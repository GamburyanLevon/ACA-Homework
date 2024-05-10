#pragma once
#include <string>

class Animal {
private:
    static int count;
protected:
    std::string name;
    int age;
    int weight;

public:
    Animal(const std::string&, const int& , const int&);
    Animal(const Animal&);

    virtual ~Animal();
    virtual int getCount() const = 0;
    virtual void print() = 0;

    virtual void voice() = 0;
};