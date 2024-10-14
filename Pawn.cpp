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
    // Calculates distance between start and end squares
    sf::Vector2f start = square->getGridPos();
    float dx = std::abs(end.x - start.x);
    float dy = (end.y - start.y); // +dy = up, -dy = down

    // Determine direction based on team color
    int direction;
    if (color == 1) {direction = -1;} 
    else {direction = 1;}

    // Valid moves are any move that is 1 square in y direction (depends on team) either straight or diagonal
    // Diagonal moves are only valid when square is occupied, however this check is done in getValidMoves()
    if ((dx == 1 || dx == 0) && dy == direction) {
        return true;
    }
    return false;
}

std::vector<Square*> Pawn::getValidMoves(Square squares[8][8]) const {
    // Initialize valid moves vector
    std::vector<Square*> validMoves;
    // Get start coordinates
    sf::Vector2f start = square->getGridPos();
    // For loop to check both y directions
    for (int y = 1; y >= -1; y -= 2) {
        // Check both diagonals & straight ahead square
        for (int x = 1; x >= -1; x--) {
            sf::Vector2f end = start + sf::Vector2f(x, y);
            Square* endSquare = &squares[(int) end.x][(int) end.y];
            if (isValidMove(end)) {
                if (std::abs(x) == 1) { // if diagonal
                    if (endSquare->getPiece() != nullptr) { // push square if occupied
                        if (endSquare->getPiece()->getColor() != color) {   // & opposite color
                            validMoves.push_back(endSquare);
                        }
                    }
                } else { // if straight ahead
                    if (endSquare->getPiece() == nullptr) { // push if unoccupied
                        validMoves.push_back(endSquare);
                    }
                    
                }
            }
        }
    }
    
    return validMoves;
}

Pawn::~Pawn() {}