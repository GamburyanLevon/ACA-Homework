#pragma once
#include "animal.h"

class Elephant : public Animal {
private:
    std::string location;
    static int count;
public:
    explicit Elephant(const std::string&,const int& age,  const int&, const std::string&);
    Elephant(Elephant&&);
    virtual void print();
    Elephant(const Elephant&);
    int getCount() const override;
    virtual void voice();
    int getAge() override;
    ~Elephant();
};
