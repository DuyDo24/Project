#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"


class Rook : public Piece {
private:
    static sf::Texture rookTexture;
public:
    // Constructor
    Rook(Square* startingSquare);
    
    // Destructor
    ~Rook() override;
    bool isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const override;
};

#endif // ROOK_H
