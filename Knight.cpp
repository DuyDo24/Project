#include "Knight.h"

Knight::Knight(const sf::Vector2f& position, Square* startingSquare, const sf::Texture& texture)
    : Piece(position, startingSquare, 3) {
    setTexture(texture);
}

bool Knight::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
    float dx = std::abs(end.x - start.x);
    float dy = std::abs(end.y - start.y);
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}
