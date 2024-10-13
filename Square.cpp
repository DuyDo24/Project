#include "Square.h"
#include "Piece.h"

Square::Square() {
    setColor(sf::Color(122,122,122,255));
    square.setSize(sf::Vector2f(50,50));
    square.setPosition(sf::Vector2f(0,0));
    piece = nullptr;
    hitbox = sf::FloatRect(square.getPosition(), square.getSize());
    gridPos = sf::Vector2f(0,0);
}

void Square::setColor(sf::Color color) {
    square.setFillColor(color);
    defaultColor = color;
    highlightedColor = color * sf::Color(255, 122, 122, 255);
}

void Square::setHighlight(bool highlighted) {
    if (highlighted == true) {
        square.setFillColor(highlightedColor);
    } else {
        square.setFillColor(defaultColor);
    }
}

void Square::setPosition(sf::Vector2f position) {
    square.setPosition(position);
    hitbox = sf::FloatRect(position, square.getSize());
}

void Square::setPiece(Piece* piece) {
    piece->setPosition(square.getPosition());
    this->piece = piece;
}

void Square::removePiece() {
    piece = nullptr;
}

Piece* Square::getPiece() {
    return piece;
}

void Square::draw(sf::RenderWindow& window) {
    window.draw(square);
    if (piece != nullptr) {
        piece->draw(window);
    }
}

sf::RectangleShape* Square::getSquare() {
    return &square;
}

// Sets square's grid position
void Square::setGridPos(sf::Vector2f& position) {
    gridPos = position;
}
// Gets square's grid position
sf::Vector2f Square::getGridPos() {
    return gridPos;
}