#ifndef KING_H
#define KING_H


#include "Piece.h"


class King : public Piece {
private:
    static sf::Texture kingTexture;
public:
    // Constructor
    King(Square* startingSquare);
    
    // Destructor
    ~King() override;
    bool isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const override;

};

#endif // KING_H
