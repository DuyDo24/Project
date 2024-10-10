#include "Queen.h"
#include <iostream>

// Static texture to be shared by all Queen instances
sf::Texture Queen::queenTexture;

// Constructor
Queen::Queen(Square* startingSquare)
    : Piece(startingSquare, 9) // 9 is the value of the Queen
{
    if (!queenTexture.loadFromFile("Chess_qlt60.png")) {
        std::cerr << "Error loading pawn texture" << std::endl;
    }
    setTexture(queenTexture);
}

bool Queen::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
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
Queen::~Queen() {}
