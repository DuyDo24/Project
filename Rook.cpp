#include "Rook.h"
#include <iostream>

// Static texture to be shared by all Rook instances
sf::Texture Rook::blackRookTexture;
sf::Texture Rook::whiteRookTexture;

// Constructor
Rook::Rook(Square* startingSquare, bool black)
    : Piece(startingSquare, 5) // 5 is the value of the Rook
{
    if (black == true) { 
        if (!blackRookTexture.loadFromFile("textures/Chess_rdt60.png")) {
            std::cerr << "Error loading knight texture" << std::endl;
        }
        setTexture(Rook::blackRookTexture);
    } else {
        if (!whiteRookTexture.loadFromFile("textures/Chess_rlt60.png")) {
            std::cerr << "Error loading knight texture" << std::endl;
        }
        setTexture(Rook::whiteRookTexture);
    }
}
bool Rook::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
    float dx = std::abs(end.x - start.x);
    float dy = std::abs(end.y - start.y);

    // Rook moves either in a straight line horizontally or vertically
    return (dx == 0 || dy == 0);
}

// Destructor
Rook::~Rook() {}
