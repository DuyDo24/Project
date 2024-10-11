#include "Square.h"
#include "Piece.h"

Square::Square() {
    square.setFillColor(sf::Color(122, 122, 122, 255)); // Default square color
    square.setSize(sf::Vector2f(50, 50));               // Default square size
    square.setPosition(sf::Vector2f(0, 0));             // Default position
    piece = nullptr;                                    // No piece initially
    hitbox = sf::FloatRect(square.getPosition(), square.getSize()); // Initialize hitbox for clicks
}

// Set the color of the square
void Square::setColor(sf::Color color) {
    square.setFillColor(color);
}

// Set the position of the square
void Square::setPosition(sf::Vector2f position) {
    square.setPosition(position);
    hitbox = sf::FloatRect(position, square.getSize()); // Update hitbox with the new position
}

// Place a piece on the square
void Square::setPiece(Piece* piece) {
    if (piece != nullptr) {
        piece->setPosition(square.getPosition());  // Sync piece position with the square
    }
    this->piece = piece;  // Assign the piece
}

// Remove the piece from the square
void Square::removePiece() {
    piece = nullptr;  // Set the piece to nullptr, meaning no piece is on the square
}

// Get the current piece on the square
Piece* Square::getPiece() {
    return piece;  // Return the pointer to the piece
}

// Draw the square and any piece on it
void Square::draw(sf::RenderWindow& window) {
    window.draw(square);  // Draw the square first
    if (piece != nullptr) {
        piece->draw(window);  // Draw the piece on the square if it exists
    }
}

// Get the underlying SFML rectangle shape of the square
sf::RectangleShape* Square::getSquare() {
    return &square;
}
