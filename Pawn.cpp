#include "Pawn.h"
#include <iostream>

sf::Texture Pawn::pawnTexture;

Pawn::Pawn(Square* startingSquare)
    : Piece(startingSquare, 1) {

    if (!pawnTexture.loadFromFile("Chess_plt60.png")) {
        std::cerr << "Error loading pawn texture" << std::endl;
    }

    setTexture(Pawn::pawnTexture);
}

bool Pawn::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
    float dx = std::abs(end.x - start.x);
    float dy = std::abs(end.y - start.y);

    if (dx == 0 && ((dy == 1) || (dy == 2 && !hasMoved))) {
        return true;
    }
    if (dx == 1 && dy == 1) {
        return true;
    }
    return false;
}