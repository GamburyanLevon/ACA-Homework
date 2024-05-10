#pragma once
#include "animal.h"

class Elephant : public Animal {
private:
    std::string location;
    static int count;
public:
    Elephant(const std::string&,const int& age,  const int&, const std::string&);

    virtual void print();
    Elephant(const Elephant&);
    int getCount() const override;
    virtual void voice();
    ~Elephant();
};
