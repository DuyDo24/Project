#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include <SFML/Graphics.hpp>

class Pawn : public Piece {
private:
    static sf::Texture whitePawnTexture;
    static sf::Texture blackPawnTexture;
public:
    Pawn(Square* startingSquare, bool black);
    bool isValidMove(const sf::Vector2f& end) const override;
};
#endif