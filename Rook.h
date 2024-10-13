#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include <vector>

class Rook : public Piece {
private:
    static sf::Texture blackRookTexture;
    static sf::Texture whiteRookTexture;
public:
    // Constructor
    Rook(Square* startingSquare, bool black);
    
    // Destructor
    ~Rook() override;

    bool isValidMove(const sf::Vector2f& end) const override;
    std::vector<Square*> getValidMoves(Square squares[8][8]) const override;
};

#endif // ROOK_H
