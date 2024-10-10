#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"


class Bishop : public Piece {
private:
    static sf::Texture bishopTexture;
public:
    // Constructor
    Bishop(Square* startingSquare);
    // Destructor
    ~Bishop() override;
    bool isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const override;

};

#endif // BISHOP_H
