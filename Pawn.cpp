#include "Pawn.h"
#include <iostream>

// Static textures for all Pawn instances
sf::Texture Pawn::whitePawnTexture;
sf::Texture Pawn::blackPawnTexture;

// Constructor
Pawn::Pawn(Square* startingSquare, bool isWhite)
    : Piece(startingSquare, 1), isWhite(isWhite), hasMoved(false)  // 1 is the value of the Pawn
{
    if (!isWhite) {
        if (!blackPawnTexture.loadFromFile("textures/Chess_pdt60.png")) {
            std::cerr << "Error loading black pawn texture" << std::endl;
        }
        setTexture(Pawn::blackPawnTexture);
    } else {
        if (!whitePawnTexture.loadFromFile("textures/Chess_plt60.png")) {
            std::cerr << "Error loading white pawn texture" << std::endl;
        }
        setTexture(Pawn::whitePawnTexture);
    }
}

// Destructor
Pawn::~Pawn() {}

bool Pawn::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
    float dx = std::abs(end.x - start.x);  // Horizontal difference
    float dy = end.y - start.y;            // Vertical difference

    // Movement for white pawns (forward is negative y)
    if (isPawnWhite()) {
        if (dx == 0 && dy == -1) {  // Move one square forward
            return true;
        }
        if (dx == 0 && dy == -2 && isFirstMove()) {  // Move two squares forward on first move
            return true;
        }
        if (dx == 1 && dy == -1) {  // Diagonal capture
            return true;
        }
    } 
    // Movement for black pawns (forward is positive y)
    else {
        if (dx == 0 && dy == 1) {  // Move one square forward
            return true;
        }
        if (dx == 0 && dy == 2 && isFirstMove()) {  // Move two squares forward on first move
            return true;
        }
        if (dx == 1 && dy == 1) {  // Diagonal capture
            return true;
        }
    }

    return false;  // If none of the conditions are met, the move is invalid
}


// Function to determine if the pawn is on its first move
bool Pawn::isFirstMove() const {
    return !hasMoved;  // The pawn is on its first move if `hasMoved` is false
}

// Function to update the pawn's move status
void Pawn::setHasMoved(bool moved) {
    hasMoved = moved;
}

// Function to check if the pawn is white
bool Pawn::isPawnWhite() const {
    return isWhite;
}