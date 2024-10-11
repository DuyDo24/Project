#ifndef PIECE_H
#define PIECE_H

#include "Drawable.h"
#include "Square.h" // Include Square if necessary
#include <iostream>

class Square; // Forward declaration

class Piece : public Drawable {
protected:
    bool hasMoved;
    Square* square;  // Pointer to the square where the piece is located
    int value;       // Value of the piece

public:
    Piece(Square* startingSquare, int val);
    virtual ~Piece();

    virtual bool isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const = 0;

    void move(const sf::Vector2f& newPosition);
    int getValue() const;

    void draw(sf::RenderWindow& window) const override;
    
    void setHasMoved(bool moved) { hasMoved = moved; } // Setter for hasMoved
};

#endif
