#include "Square.h"
#include "Piece.h"

Square::Square() {
    square.setFillColor(sf::Color(122,122,122,255));
    square.setSize(sf::Vector2f(50,50));
    square.setPosition(sf::Vector2f(0,0));
    piece = nullptr;
}

void Square::setColor(sf::Color color) {
    square.setFillColor(color);
}

// void Square::setPosition(sf::Vector2f position) {
//     square.setPosition(position);
// }

void Square::setPiece(Piece* piece) {
    piece->setPosition(square.getPosition());
    this->piece = piece;
}

void Square::removePiece() {
    piece = nullptr;
}

Piece* Square::getPiece() {
    return piece;
}

void Square::draw(sf::RenderWindow& window) {
    window.draw(square);
    if (piece != nullptr) {
        piece->draw(window);
    }
    
}

sf::RectangleShape* Square::getSquare() {
    return &square;
}