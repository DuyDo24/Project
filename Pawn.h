#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
private:
    static sf::Texture whitePawnTexture;  // Static texture for white pawn
    static sf::Texture blackPawnTexture;  // Static texture for black pawn

public:
    Pawn(Square* startingSquare, bool black);  // Constructor to initialize pawn
    bool isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const override;  // Pawn move validation
};

#endif
