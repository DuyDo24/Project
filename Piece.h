#ifndef PIECE_H
#define PIECE_H

#include "Drawable.h"

class Square;

class Piece : public Drawable {
protected:
    bool hasMoved;
    Square* square;
    int value;  // Value of the piece

public:
    Piece(Square* startingSquare, int val);
    virtual ~Piece();

    virtual bool isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const = 0;

    void move(const sf::Vector2f& newPosition);
    int getValue() const;

    void draw(sf::RenderWindow& window) const override;
};

#endif
