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

    board.placepiece("B8", new queen("B8", "White"));
    // board.placepiece("G7", new pawn("G7", "White"));
    // board.placepiece("A7", new rook("A7", "White"));
    // board.placepiece("C2", new rook("C2", "White"));
    // board.placepiece("H4", new rook("H4", "White"));
    // board.placepiece("G1", new bishop("G1", "White"));
    // board.placepiece("G3", new bishop("G3", "White"));
    // board.placepiece("C7", new pawn("C7", "White"));
    // board.placepiece("A1", new pawn("A1", "White"));
    board.placepiece("A8", new king("A8", "Black"));
    board.placepiece("C8", new king("C8", "White"));
    // board.placepiece("B1", new rook("B1", "White"));
    // board.placepiece("A7", new rook("A7", "White"));
    // board.placepiece("F6", new knight("F6", "White"));

    if (board.get())
    {
        board.print();
    
        std::cout << std::endl;
        if (!board.checkmateinone())
        {
            std::cout << "there is no mate";
        }
    
        std::cout << std::endl;
    }
    
    return 0;
}