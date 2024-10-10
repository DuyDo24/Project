#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
private:
    static sf::Texture pawnTexture;
public:
    Pawn(Square* startingSquare);
    bool isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const override;
};
#endif
