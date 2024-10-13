#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include <vector>

class Knight : public Piece {
private:
    static sf::Texture whiteKnightTexture;
    static sf::Texture blackKnightTexture;
public:
    // Constructor
    Knight(Square* startingSquare, bool black);
    
    // Destructor
    ~Knight() override;
    bool isValidMove(const sf::Vector2f& end) const override;
    std::vector<Square*> getValidMoves(Square squares[8][8]) const override;

};

#endif // KNIGHT_H