#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include <SFML/Graphics.hpp>

class Pawn : public Piece {
private:
    static sf::Texture whitePawnTexture;
    static sf::Texture blackPawnTexture;
public:
    // Constructor
    Pawn(Square* startingSquare, bool black);

    // Destructor
    ~Pawn();
    bool isValidMove(const sf::Vector2f& end) const override;
    std::vector<Square*> getValidMoves(Square squares[8][8]) const override;
};
#endif