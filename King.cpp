#include "King.h"
#include <iostream>

// Static texture to be shared by all King instances
sf::Texture King::blackKingTexture;
sf::Texture King::whiteKingTexture;

// Constructor
King::King(Square* startingSquare, bool black)
    : Piece(startingSquare, 0) // 0 is the value of the King (or you can use a different value)
{
    if (black == true) { 
        if (!blackKingTexture.loadFromFile("textures/Chess_kdt60.png")) {
            std::cerr << "Error loading king texture" << std::endl;
        }
        setTexture(King::blackKingTexture);
    } else {
        if (!whiteKingTexture.loadFromFile("textures/Chess_klt60.png")) {
            std::cerr << "Error loading king texture" << std::endl;
        }
        setTexture(King::whiteKingTexture);
    }
}
bool King::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
    float dx = std::abs(end.x - start.x);
    float dy = std::abs(end.y - start.y);

    // King moves one square in any direction
    return (dx <= 1 && dy <= 1);
}


// Destructor
King::~King() {}
