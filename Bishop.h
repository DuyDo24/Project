#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(const sf::Vector2f& position, Square* startingSquare, const sf::Texture& texture);

    bool isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const override;
};

#endif
