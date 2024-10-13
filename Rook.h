#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include "Board.h"


class Rook : public Piece {
private:
    static sf::Texture blackRookTexture;
    static sf::Texture whiteRookTexture;
public:
    // Constructor
    Rook(Square* startingSquare, bool black);
    
    // Destructor
    ~Rook() override;
    bool isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const override;
};

#endif // ROOK_H
