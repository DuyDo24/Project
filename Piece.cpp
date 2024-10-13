#include "Piece.h"
#include "Square.h"
#include <string>

//vectors for white and black pieces shared with all pieces
std::vector<Piece*> Piece::whitePieces;
std::vector<Piece*> Piece::blackPieces;

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

std::string Piece::getName() const {
    return name;
}

int Piece::getColor() {
    return color;
}

void Piece::draw(sf::RenderWindow& window) const {
    window.draw(image);
}

