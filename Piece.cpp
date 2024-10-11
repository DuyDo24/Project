#include "Piece.h"

// Constructor
Piece::Piece(Square* startingSquare, int val) : square(startingSquare), value(val), hasMoved(false) {
    if (square != nullptr) {
        setPosition(square->getPosition()); // Set the piece's position based on its square
    }
}

// Destructor
Piece::~Piece() {
    // Destructor logic, if needed (e.g., managing ownership of `Square*`)
}

// Method to move the piece to a new position
void Piece::move(const sf::Vector2f& newPosition) {
    setPosition(newPosition);  // Set the Drawable's position
    hasMoved = true;
    
    // Potentially update the piece's current square here, if needed:
    // square = getSquareAt(newPosition);  // Update logic as necessary
}

// Get the value of the piece
int Piece::getValue() const {
    return value;
}

// Method to draw the piece
void Piece::draw(sf::RenderWindow& window) const {
    window.draw(image); // Draw the piece's sprite
}
