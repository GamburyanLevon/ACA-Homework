#include "figure.h"
#pragma once

class chessboard
{
private:
    figure* board[8][8];
    static bool isInBoard;
public:
    chessboard();
   ~chessboard();
    void placePiece(figure*);
    bool checkmateInOne(const std::string&);
    bool checkmateInTwo();
    bool isCheckmate(const std::string&);
    bool isCheck(const std::string&);
    void print();
    static bool getPlacement();
    bool canCapture(const std::string&);
    bool canPlaceKingAt(int, int);
};