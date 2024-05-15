#pragma once
#include "figure.h"

class knight : public figure
{
public:
    knight(const std::string&, const std::string&);
    ~knight();
    virtual bool isAttacking(const std::string&, figure* board[8][8]);
    virtual void move(const std::string&);
    void print() override;
    char getSymbol() const override;
    int getRow() const override;
    int getCol() const override;
};