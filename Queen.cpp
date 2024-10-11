#include "Queen.h"
#include <iostream>

// Static texture to be shared by all Queen instances
sf::Texture Queen::queenTexture;

// Constructor
Queen::Queen(Square* startingSquare)
    : Piece(startingSquare, 9) // 9 is the value of the Queen
{
    if (!queenTexture.loadFromFile("textures/Chess_qlt60.png")) {
        std::cerr << "Error loading pawn texture" << std::endl;
    }
    setTexture(queenTexture);
}

bool Queen::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
    
}
// Destructor
Queen::~Queen() {}
