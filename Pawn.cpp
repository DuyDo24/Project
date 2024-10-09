#include "Pawn.h"

Pawn::Pawn(const sf::Vector2f& position, Square* startingSquare, const sf::Texture& texture)
    : Piece(position, startingSquare, 1) {
    setTexture(texture);
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
