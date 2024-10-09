#include "King.h"

King::King(const sf::Vector2f& position, Square* startingSquare, const sf::Texture& texture)
    : Piece(position, startingSquare, 100) {  // Arbitrary large value for King
    setTexture(texture);
}

bool King::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
    float dx = std::abs(end.x - start.x);
    float dy = std::abs(end.y - start.y);
    return dx <= 1 && dy <= 1;
}
