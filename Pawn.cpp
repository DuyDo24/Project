#include "Pawn.h"
#include "Square.h"
#include <iostream>

sf::Texture Pawn::whitePawnTexture;
sf::Texture Pawn::blackPawnTexture;

Pawn::Pawn(Square* startingSquare, bool black)
    : Piece(startingSquare, 1) {
    // Set sprite based on color
    if (black == true) { 
        if (!blackPawnTexture.loadFromFile("textures/Chess_pdt60.png")) {
            std::cerr << "Error loading pawn texture" << std::endl;
        }
        blackPieces.push_back(this);
        setTexture(Pawn::blackPawnTexture);
        color = 0;
    } else {
        if (!whitePawnTexture.loadFromFile("textures/Chess_plt60.png")) {
            std::cerr << "Error loading pawn texture" << std::endl;
        }
        whitePieces.push_back(this);
        setTexture(Pawn::whitePawnTexture);
        color = 1;
    }
    name = "Pawn";
}

// Returns move validity given integer start and end coordinates
bool Pawn::isValidMove(const sf::Vector2f& end) const {
    // Return false if target coordinates outside of 8x8 (i.e < 0 or > 7)
    if (end.x < 0 || end.x > 7) { 
        return false;
    }
    if (end.y < 0 || end.y > 7) { 
        return false;
    }
    // Calculates absolute distance between start and end squares
    // Absolute distance can be used as the knight is directionally agnostic and it can move through pieces
    // which means no checks are needed for blocking pieces
    sf::Vector2f start = square->getGridPos();
    float dx = std::abs(end.x - start.x);
    float dy = std::abs(end.y - start.y);

    // Valid moves are any move that is 1 square away in 1 direction and 2 squares away in a different direction
    // i.e dx = 1, dy = 2 or dx = 2, dy = 1
    if (dx == 2 && dy == 1) {
        return true;
    }
    if (dx == 1 && dy == 2) {
        return true;
    }
    return false;
}