#pragma once
#include "figure.h"

class knight : public figure
{
public:
    knight(const std::string&, const std::string&);
    ~knight();
    virtual bool isAttacking(const std::string&);
    virtual void move(const std::string&);
    void print() override;
};