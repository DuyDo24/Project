#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop: public Piece {
private:
    static sf::Texture blackBishopTexture;
    static sf::Texture whiteBishopTexture;

public:
    // Constructor
    Bishop(Square* startingSquare, bool black);
    
    // Destructor
    ~Bishop() override;
    bool isValidMove(const sf::Vector2f& end) const override;
    std::vector<Square*> getValidMoves(Square squares[8][8]) const override;
};

#endif 