#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
public:
    King(const sf::Vector2f& position, Square* startingSquare, const sf::Texture& texture);

    bool isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const override;
};

#endif
