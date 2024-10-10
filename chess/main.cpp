#include <iostream>
#include "figure.h"
#include "bishop.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
#include "pawn.h"
#include "king.h"
#include "chessboard.h"

int main()
{
    chessboard board;

    board.placePiece(new queen("G1", "White"));
    // board.placePiece(new pawn("E7", "White"));
    // board.placePiece(new rook("A7", "White"));
    // board.placePiece(new rook("C2", "White"));
    // board.placePiece(new rook("H4", "White"));
    // board.placePiece(new bishop("G1", "White"));
    // board.placePiece(new bishop("G3", "White"));
    // board.placePiece(new pawn("C7", "White"));
    // board.placePiece(new pawn("A1", "White"));
    board.placePiece(new king("G8", "Black"));
    board.placePiece(new king("G6", "White"));
    // board.placePiece(new queen("A5", "White"));
    // board.placePiece(new rook("B1", "White"));
    // board.placePiece(new rook("A7", "White"));
    // board.placePiece(new knight("F6", "White"));

    if (board.getPlacement())
    {
        board.print();
    
        if (!board.checkmateInTwo())
        {
            std::cout << "there is no mate";
        }
        else
        {
            // board.print();
            std::cout << "After this is mate in one" << std::endl;
        }
        std::cout << std::endl;
    }
    
    return 0;
}