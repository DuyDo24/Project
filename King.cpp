#include "King.h"
#include <iostream>

// Static texture to be shared by all King instances
sf::Texture King::kingTexture;

// Constructor
King::King(Square* startingSquare)
    : Piece(startingSquare, 0) // 0 is the value of the King (or you can use a different value)
{
    if (!kingTexture.loadFromFile("textures/Chess_klt60.png")) {
        std::cerr << "Error loading pawn texture" << std::endl;
    }
    setTexture(kingTexture);
}
bool King::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
    float dx = std::abs(end.x - start.x);
    float dy = std::abs(end.y - start.y);

    if (dx == 0 && ((dy == 1) || (dy == 2 && !hasMoved))) {
        return true;
    }
    if (dx == 1 && dy == 1) {
        return true;
    }
    return false;
}

// Destructor
King::~King() {}
