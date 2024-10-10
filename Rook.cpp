#include "Rook.h"
#include <iostream>

// Static texture to be shared by all Rook instances
sf::Texture Rook::rookTexture;

// Constructor
Rook::Rook(Square* startingSquare)
    : Piece(startingSquare, 5) // 5 is the value of the Rook
{

    if (!rookTexture.loadFromFile("Chess_rlt60.png")) {
        std::cerr << "Error loading pawn texture" << std::endl;
    }
    setTexture(rookTexture);
}

bool Rook::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
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
Rook::~Rook() {}
