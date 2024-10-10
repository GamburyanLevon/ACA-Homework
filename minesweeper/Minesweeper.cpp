#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Minesweeper.h"

Minesweeper::Minesweeper(int r, int c, int m) : rows(r), cols(c), mines(m), flags(m)
{
    board.resize(rows, std::vector<char>(cols, ' '));
    display.resize(rows, std::vector<char>(cols, '#'));
    setupBoard();
}

bool Minesweeper::isInBounds(int row, int col)
{
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

int Minesweeper::countMinesAround(int row, int col)
{
    int mineCount = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (isInBounds(row + i, col + j) && board[row + i][col + j] == '*')
            {
                mineCount++;
            }
        }
    }
    return mineCount;
}

void Minesweeper::setupBoard()
{
    srand(time(0));

    int placedMines = 0;
    while (placedMines < mines)
    {
        int r = rand() % rows;
        int c = rand() % cols;
        if (board[r][c] != '*')
        {
            board[r][c] = '*';
            placedMines++;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] != '*')
            {
                int mineCount = countMinesAround(i, j);
                board[i][j] = mineCount == 0 ? ' ' : mineCount + '0';
            }
        }
    }
}

void Minesweeper::reveal(int row, int col)
{
    if (!isInBounds(row, col) || display[row][col] != '#')
    {
        return;
    }

    display[row][col] = board[row][col];
    if (board[row][col] == ' ')
    {
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                reveal(row + i, col + j);
            }
        }
    }
}

void Minesweeper::printDisplayBoard()
{
    std::cout << "  ";
    for (int i = 0; i < cols; i++)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < rows; i++)
    {
        std::cout << i << " ";
        for (int j = 0; j < cols; j++)
        {
            std::cout << display[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void Minesweeper::placeFlag(int row, int col)
{
    if (!isInBounds(row, col))
    {
        return;
    }
    if (flags == 0)
    {
        std::cout << "You have no more flags" << std::endl;
        return;
    }

    display[row][col] = 'F';
    --flags;
}

bool Minesweeper::makeMove(int row, int col)
{
    if (!isInBounds(row, col))
    {
        std::cout << "Move out of bounds. Try again.\n";
        return true;
    }

    if (board[row][col] == '*')
    {
        std::cout << "BOOM! You hit a mine. Game over.\n";
        return false;
    }

    reveal(row, col);
    return true;
}

bool Minesweeper::isWin()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (display[i][j] == '#' && board[i][j] != '*')
            {
                return false;
            }
        }
    }
    return true;
}