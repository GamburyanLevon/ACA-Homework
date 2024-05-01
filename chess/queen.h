#pragma once
#include "figure.h"

class queen : public figure
{
public:
    queen(const std::string&, const std::string&);
    ~queen();
    virtual bool isAttacking(const std::string&);
    virtual void move(const std::string&);
    void print() override;
};