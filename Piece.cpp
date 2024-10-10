#include "Piece.h"

Piece::Piece(const sf::Vector2f& position, Square* startingSquare, int val)
    : Drawable(position), hasMoved(false), square(startingSquare), value(val) {}

Piece::~Piece() {}

void Piece::move(const sf::Vector2f& newPosition) {
    
}

int Piece::getValue() const {
    return value;
}

void Piece::draw(sf::RenderWindow& window) const {
    window.draw(image);
}
