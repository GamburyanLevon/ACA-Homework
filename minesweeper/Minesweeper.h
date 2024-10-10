#pragma once
#include <vector>

class Minesweeper
{
private:
    int rows, cols, mines;
    std::vector<std::vector<char> > board;
    std::vector<std::vector<char> > display;

    bool isInBounds(int row, int col);
    int countMinesAround(int row, int col);
    void setupBoard();
    void reveal(int row, int col);

public:
    int flags;
    Minesweeper(int r, int c, int m);
    void printDisplayBoard();
    void placeFlag(int row, int col);
    bool makeMove(int row, int col);
    bool isWin();
};