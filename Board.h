#ifndef BOARD_H
#define BOARD_H
#include "Square.h"

class Board {
    private:
        Square squares[8][8];
    public:
        Board();
        void getSquare(sf::Vector2f& gridPosition);
        void drawBoard(sf::RenderWindow& window);
};

#endif