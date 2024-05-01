#pragma once
#include "figure.h"

class rook : public figure
{
public:
    rook(const std::string&, const std::string&);
    ~rook();
    virtual bool isAttacking(const std::string&);
    virtual void move(const std::string&);
    void print() override;
};