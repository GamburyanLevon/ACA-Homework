#pragma once
#include "figure.h"

class pawn : public figure
{
public:
    pawn(const std::string&, const std::string&);
    ~pawn();
    bool isAttacking(const std::string&, figure* board[8][8]) override;
    void move(const std::string&) override;
    void print() override;
    char getSymbol() const override;
    int getRow() const override;
    int getCol() const override;
    std::string getColor() const override;
};