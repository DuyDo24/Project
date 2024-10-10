#ifndef PIECE_H
#define PIECE_H

#include "Drawable.h"
#include "Square.h"

class Piece : public Drawable {
protected:
    bool hasMoved;
    Square* square;
    int value;  // Value of the piece

public:
    Piece(const sf::Vector2f& position, Square* startingSquare, int val);
    virtual ~Piece();
    void move(const sf::Vector2f& newPosition);
    int getValue() const;
    void draw(sf::RenderWindow& window) const override;
};

#endif
