#include <iostream>
#include "figure.h"
#include "bishop.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
#include "pawn.h"

int main()
{
    pawn* whitepawn = new pawn("A2", "white");
    pawn* blackpawn = new pawn("D7", "black");
    knight* whiteknight = new knight("G1", "white");
    knight* blackknight = new knight("B8", "black");
    bishop* whitebishop = new bishop("C1", "white");
    bishop* blackbishop = new bishop("F8", "black");
    rook* whiterook = new rook("H1", "white");
    rook* blackrook = new rook("A8", "black");
    queen* whitequeen = new queen("D1", "white");
    queen* blackqueen = new queen("D8", "black");

    std::string pos[] ={"A3", "D6", "F3", "C6", "F4", "B4", "H3", "E8", "B3", "F6"};

    figure* figures[] = {whitepawn, blackpawn, whiteknight,blackknight, whitebishop, blackbishop,
        whiterook, blackrook, whitequeen, blackqueen};
    int i = 0;
    for (figure* figure : figures)
    {
        figure->move(pos[i]);
        figure->print();
        i++;
    }
    for (figure* figure : figures)
    {
        delete figure;
    }
    
}