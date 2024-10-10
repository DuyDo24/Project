#include "Knight.h"
#include <iostream>

// Static texture to be shared by all Knight instances
sf::Texture Knight::knightTexture;

// Constructor
Knight::Knight(Square* startingSquare)
    : Piece(startingSquare, 3) // 3 is the value of the Knight
{

     if (!knightTexture.loadFromFile("Chess_nlt60.png")) {
        std::cerr << "Error loading pawn texture" << std::endl;
    }
    setTexture(knightTexture);

}
bool Knight::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
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
Knight::~Knight() {}
