#pragma once
#include "figure.h"

class bishop : public figure
{
public:
    bishop(const std::string&, const std::string&);
    ~bishop();
    virtual bool isAttacking(const std::string&, figure* board[8][8]);
    virtual void move(const std::string&);
    void print() override;
    char getSymbol() const override;
    int getRow() const override;
    int getCol() const override;
    std::string getColor() const override;
};