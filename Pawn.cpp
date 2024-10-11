#include "Pawn.h"
#include <iostream>

sf::Texture Pawn::whitePawnTexture;
sf::Texture Pawn::blackPawnTexture;

// Constructor
Pawn::Pawn(Square* startingSquare, bool black)
    : Piece(startingSquare, 1) {
    // Load textures only if they are not already loaded
    if (black) {
        if (blackPawnTexture.getSize().x == 0) { // Check if texture is already loaded
            if (!blackPawnTexture.loadFromFile("textures/Chess_pdt60.png")) {
                std::cerr << "Error loading black pawn texture" << std::endl;
            }
        }
        setTexture(blackPawnTexture);  // Set texture for black pawn
    } else {
        if (whitePawnTexture.getSize().x == 0) { // Check if texture is already loaded
            if (!whitePawnTexture.loadFromFile("textures/Chess_plt60.png")) {
                std::cerr << "Error loading white pawn texture" << std::endl;
            }
        }
        setTexture(whitePawnTexture);  // Set texture for white pawn
    }
}

bool Pawn::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
    // Calculate the change in positions
    float dx = end.x - start.x;  // Change in x
    float dy = end.y - start.y;  // Change in y

    // If the piece is white (moving upwards)
    if (start.y > end.y) {
        // Check for regular move
        if (dx == 0) { // No horizontal movement
            if (dy == -50 && !hasMoved) { // Initial double move
                return true; // Valid two-square move
            }
            if (dy == -50 && hasMoved) { // Regular one-square move
                return true; // Valid one-square move
            }
        }
        // Check for diagonal capture
        if (std::abs(dx) == 50 && dy == -50) { // One square diagonally up
            return true; // Valid diagonal capture move
        }
    }
    // If the piece is black (moving downwards)
    else {
        // Check for regular move
        if (dx == 0) { // No horizontal movement
            if (dy == 50 && !hasMoved) { // Initial double move
                return true; // Valid two-square move
            }
            if (dy == 50 && hasMoved) { // Regular one-square move
                return true; // Valid one-square move
            }
        }
        // Check for diagonal capture
        if (std::abs(dx) == 50 && dy == 50) { // One square diagonally down
            return true; // Valid diagonal capture move
        }
    }

    return false; // Invalid move
}

