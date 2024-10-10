#ifndef BOARD_H
#define BOARD_H
#include "Square.h"

class Board {
    private:
        Square squares[8][8];
    public:
        Board();
        Square* getChessSquare(int x, int y);
        void drawBoard(sf::RenderWindow& window);
};

#endif