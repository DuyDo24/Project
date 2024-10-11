#ifndef SQUARE_H
#define SQUARE_H

#include "Clickable.h"
#include <SFML/Graphics.hpp>
#include "Piece.h" // Include Piece here after its definition

class Square : public Clickable {
private:
    sf::RectangleShape square;
    Piece* piece;  // Pointer to the piece on this square
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
