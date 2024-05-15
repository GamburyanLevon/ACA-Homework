#include "figure.h"
#pragma once

class chessboard
{
private:
    figure* board[8][8];
    static bool isInBoard;
public:
    chessboard();
    void placepiece(const std::string&, figure*);
    bool checkmateinone(const std::string&);
    bool isCheckmate(const std::string&);
    bool ischeck(const std::string&);
    void print();
    static bool get();
    bool cancapture(const std::string&);
    ~chessboard();
};