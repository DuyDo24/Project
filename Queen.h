#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"


class Queen : public Piece {
private:
    static sf::Texture blackQueenTexture;
    static sf::Texture whiteQueenTexture;

public:
    // Constructor
    Queen(Square* startingSquare, bool black);
    
    // Destructor
    ~Queen() override;
    bool isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const override;

};

#endif // QUEEN_H
