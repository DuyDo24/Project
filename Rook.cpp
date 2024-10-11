#include "Rook.h"
#include <iostream>

// Static texture to be shared by all Rook instances
sf::Texture Rook::rookTexture;

// Constructor
Rook::Rook(Square* startingSquare)
    : Piece(startingSquare, 5) // 5 is the value of the Rook
{

    if (!rookTexture.loadFromFile("textures/Chess_rlt60.png")) {
        std::cerr << "Error loading pawn texture" << std::endl;
    }
    setTexture(rookTexture);
}

bool Rook::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
  
}
// Destructor
Rook::~Rook() {}
