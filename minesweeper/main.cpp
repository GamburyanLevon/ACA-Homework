#include <iostream>
#include "Minesweeper.h"

int main()
{
    char gameMode;
    std::cout << "Choose the difficulty[Easy: e / Difficult: d] ";
    std::cin >> gameMode;
    int rows, cols, mines;
    switch (gameMode)
    {
    case 'e':
        rows = 8;
        cols = 10;
        mines = 10;
        break;
    case 'd':
        rows = 14;
        cols = 18;
        mines = 40;
        break;
    
    default:
        rows = 5;
        cols = 5;
        mines = 2;
        break;
    }
    
    Minesweeper game(rows, cols, mines);

    std::cout << "\nWelcome to Minesweeper!\n";

    bool gameRunning = true;
    while (gameRunning)
    {
        bool useF;
        char f;
        game.printDisplayBoard();
        int row, col;
        std::cout << "You have " << game.flags << " flags" << std::endl;
        std::cout << "Do you will use the flag? [Y/N]: ";
        std::cin >> f;
        std::cout << "Enter your move (row and column): ";
        std::cin >> row >> col;
        if(f == 'Y' || f == 'y')
        {
            game.placeFlag(row, col);
        }
        else
        {
            gameRunning = game.makeMove(row, col);
        }
        if (game.isWin())
        {
            std::cout << "Congratulations! You've cleared the board!\n";
            gameRunning = false;
        }
    }

    return 0;
}
