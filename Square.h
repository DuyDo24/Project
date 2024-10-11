#ifndef SQUARE_H
#define SQUARE_H

//#include "Drawable.h"
#include "Clickable.h"
#include <SFML/Graphics.hpp>

class Piece;
class Square : public Clickable {
    private:
        sf::RectangleShape square;
        Piece* piece;
        sf::Vector2f gridPos;
    public:
        Square();
        
        sf::RectangleShape* getSquare();

        void setColor(sf::Color color);

        void setPiece(Piece* piece);
        void removePiece();
        Piece* getPiece();

        void setPosition(sf::Vector2f position);

        void draw(sf::RenderWindow& window);
};

#endif