#ifndef SQUARE_H
#define SQUARE_H

//#include "Drawable.h"
#include <SFML/Graphics.hpp>

class Piece;
class Square {
    private:
        sf::RectangleShape square;
        Piece* piece;
    public:
        Square();
        sf::RectangleShape* getSquare();
        void setColor(sf::Color color);
        void setPiece(Piece* piece);
        void removePiece();
        Piece* getPiece();
        void draw(sf::RenderWindow& window);
};

#endif