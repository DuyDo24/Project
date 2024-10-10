#include "Pawn.h"
#include <iostream>

// Static texture to be shared by all Pawn instances (to avoid loading the texture multiple times)
sf::Texture Pawn::pawnTexture;

// Constructor
Pawn::Pawn(const sf::Vector2f& position, Square* square)
    : Piece(position, square, 1) // 1 is the value of the Pawn
{
    // Load the texture if it hasn't been loaded yet
    if (!pawnTexture.loadFromFile("pawn.png")) {
        std::cerr << "Error loading pawn texture" << std::endl;
    }
    // Set the texture and position for the pawn
    setTexture(pawnTexture);
    setPosition(position);
}


// Destructor
Pawn::~Pawn() {}
