#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    Knight(const sf::Vector2f& position, Square* startingSquare, const sf::Texture& texture);

    bool isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const override;
};

#endif
