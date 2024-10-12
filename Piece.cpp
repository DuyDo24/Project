#include "Piece.h"
#include "Square.h"

Piece::Piece(Square* startingSquare, int val)
    : hasMoved(false), square(startingSquare), value(val) {
        square->setPiece(this);
        point = square->getSquare()->getPosition();
        setPosition(point);
    }

Piece::~Piece() {}

void Piece::move(const sf::Vector2f& newPosition) {
    if (isValidMove(point, newPosition)) {
        setPosition(newPosition);
        hasMoved = true;
    }
}

int Piece::getValue() const {
    return value;
}

void Piece::draw(sf::RenderWindow& window) const {
    window.draw(image);
}