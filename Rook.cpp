#include "Rook.h"

Rook::Rook(const sf::Vector2f& position, Square* startingSquare, const sf::Texture& texture)
    : Piece(position, startingSquare, 5) {
    setTexture(texture);
}

bool Rook::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
    return (start.x == end.x || start.y == end.y);
}
