#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:
    Queen(const sf::Vector2f& position, Square* startingSquare, const sf::Texture& texture);

    bool isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const override;
};

#endif
