#pragma once
#include "figure.h"

class pawn : public figure
{
public:
    pawn(const std::string&, const std::string&);
    ~pawn();
    bool isAttacking(const std::string&) override;
    virtual void move(const std::string&) override;
    void print() override;
};