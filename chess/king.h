#pragma once
#include "figure.h"

class king : public figure
{
public:
    king(const std::string&, const std::string&);
    ~king();
    virtual bool isAttacking(const std::string&, figure* board[8][8]);
    virtual void move(const std::string&);
    void print() override;
    char getSymbol() const override;
    int getRow() const override;
    int getCol() const override;
};