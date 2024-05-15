#include "figure.h"
#pragma once

class chessboard
{
private:
    figure* board[8][8];
public:
    chessboard();
    void placepiece(const std::string&, figure*);
    figure* getpiece(const std::string&) const;
    bool checkmate();
    ~chessboard();
};