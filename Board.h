#ifndef BOARD_H
#define BOARD_H

#include "Square.h"
#include "Pawn.h"

class Board {
private:
    Square squares[8][8];

public:
    Board();
    Square* getChessSquare(int x, int y);
    void movePiece(Square* current, Square* target);
    void drawBoard(sf::RenderWindow& window);
};

#endif
