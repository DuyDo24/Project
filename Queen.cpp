#include "Queen.h"

Queen::Queen(const sf::Vector2f& position, Square* startingSquare, const sf::Texture& texture)
    : Piece(position, startingSquare, 9) {
    setTexture(texture);
}

bool Queen::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
    float dx = std::abs(end.x - start.x);
    float dy = std::abs(end.y - start.y);
    return (start.x == end.x || start.y == end.y || dx == dy);
}
