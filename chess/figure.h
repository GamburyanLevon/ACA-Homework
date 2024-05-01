#pragma once
#include <string>

class figure
{
protected:
    std::string position;
    std::string color;
public:
    figure(const std::string&, const std::string&);
    virtual ~figure();
    virtual bool isAttacking(const std::string&) = 0;
    virtual void move(const std::string&) = 0;
    virtual void print() = 0;
};