#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"


class Queen : public Piece {
private:
    static sf::Texture queenTexture;

public:
    // Constructor
    Queen(Square* startingSquare);
    
    // Destructor
    ~Queen() override;
    bool isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const override;

};

#endif // QUEEN_H
