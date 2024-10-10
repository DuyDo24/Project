#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    // Constructor with position and square pointer
    Pawn(const sf::Vector2f& position, Square* square);


    // Destructor
    ~Pawn() override;

private:
    // Static texture shared by all Pawn instances
    static sf::Texture pawnTexture;
};

#endif
