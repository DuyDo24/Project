#include "Square.h"
#include "Piece.h"

// Default constructor
Square::Square() {
    setColor(sf::Color(122,122,122,255));
    square.setSize(sf::Vector2f(50,50));
    square.setPosition(sf::Vector2f(0,0));
    piece = nullptr;
    hitbox = sf::FloatRect(square.getPosition(), square.getSize());
    gridPos = sf::Vector2f(0,0);
}

// Return the square's RectangleShape object
sf::RectangleShape* Square::getSquare() {
    return &square;
}

// Set default color of square and set highlighted color to red-shifted version of default color
void Square::setColor(sf::Color color) {
    square.setFillColor(color);
    defaultColor = color;
    // Multiply RGB values of default color, reducing blue and green and keeping red the same to produce highlight color
    highlightedColor = color * sf::Color(255, 122, 122, 255);
}

// Set highlighted status of square (swaps RectangleShape fill color between default/highlighted)
void Square::setHighlight(bool highlighted) {
    if (highlighted == true) {
        square.setFillColor(highlightedColor);
    } else {
        square.setFillColor(defaultColor);
    }
}

// Set position of square's RectangleShape and hitbox
void Square::setPosition(sf::Vector2f position) {
    square.setPosition(position);
    hitbox = sf::FloatRect(position, square.getSize());
}

// Draws square and associated piece
void Square::draw(sf::RenderWindow& window) {
    window.draw(square);
    if (piece != nullptr) { // Check if square contains a piece
        piece->draw(window);
    }
}

// Sets square's associated piece
void Square::setPiece(Piece* piece) {
    piece->setPosition(square.getPosition());
    this->piece = piece;
}

// Sets square's associated piece to null
void Square::removePiece() {
    piece = nullptr;
}

// Returns associated piece
Piece* Square::getPiece() {
    return piece;
}

// Sets square's grid position
void Square::setGridPos(sf::Vector2f& position) {
    gridPos = position;
}
// Gets square's grid position
sf::Vector2f Square::getGridPos() {
    return gridPos;
}