#include "Bishop.h"

Bishop::Bishop(const sf::Vector2f& position, Square* startingSquare, const sf::Texture& texture)
    : Piece(position, startingSquare, 3) {
    setTexture(texture);
}

bool Bishop::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
    return std::abs(end.x - start.x) == std::abs(end.y - start.y);
}
