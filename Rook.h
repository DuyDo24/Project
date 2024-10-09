#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    Rook(const sf::Vector2f& position, Square* startingSquare, const sf::Texture& texture);

    bool isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const override;
};

#endif
