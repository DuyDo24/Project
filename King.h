#ifndef KING_H
#define KING_H

#include "Piece.h"
#include <vector>

class King : public Piece {
private:
    static sf::Texture blackKingTexture;
    static sf::Texture whiteKingTexture;
public:
    // Constructor
    King(Square* startingSquare, bool black);
    
    // Destructor
    ~King() override;
    
    bool isValidMove(const sf::Vector2f& end) const override;
    std::vector<Square*> getValidMoves(Square squares[8][8]) const override;
};

#endif // KING_H