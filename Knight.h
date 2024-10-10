#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"


class Knight : public Piece {
private:
    static sf::Texture knightTexture;
public:
    // Constructor
    Knight(Square* startingSquare);
    
    // Destructor
    ~Knight() override;
    bool isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const override;

};

#endif // KNIGHT_H
