#pragma once
#include "figure.h"

class bishop : public figure
{
public:
    bishop(const std::string&, const std::string&);
    ~bishop();
    virtual bool isAttacking(const std::string&);
    virtual void move(const std::string&);
    void print() override;
};