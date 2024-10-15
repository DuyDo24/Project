#include "Pawn.h"
#include "Square.h"
#include <iostream>

// Static texture to be shared by all Pawn instances
sf::Texture Pawn::whitePawnTexture;
sf::Texture Pawn::blackPawnTexture;

// Constructor
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
    int direction = (color == 1) ? -1 : 1;

    // Pawn can move two squares forward on the first move
    if (dx == 0 && (dy == direction || (dy == 2 * direction && !hasMoved))) {
        return true;
    }
    // Pawn can capture diagonally if an opponent's piece is present
    if (dx == 1 && dy == direction && square->getPiece() != nullptr) {
        return true;
    }

    return false;
}

std::vector<Square*> Pawn::getValidMoves(Square squares[8][8]) const {
    // Initialize valid moves vector
    std::vector<Square*> validMoves;
    // Get start coordinates
    sf::Vector2f start = square->getGridPos();
    
    // Direction is 1 for black, -1 for white
    int direction = (color == 1) ? -1 : 1;

    // Single square forward
    sf::Vector2f end = start + sf::Vector2f(0, direction);
    Square* forwardSquare = &squares[(int) end.x][(int) end.y];
    if (forwardSquare->getPiece() == nullptr) {
        validMoves.push_back(forwardSquare);

        // Two squares forward (only on first move)
        if (!hasMoved) {
            end = start + sf::Vector2f(0, 2 * direction);
            forwardSquare = &squares[(int) end.x][(int) end.y];
            if (forwardSquare->getPiece() == nullptr) {
                validMoves.push_back(forwardSquare);
            }
        }
    }

    // Diagonal captures
    for (int dx = -1; dx <= 1; dx += 2) {  // Check both diagonals
        end = start + sf::Vector2f(dx, direction);
        if (end.x >= 0 && end.x < 8 && end.y >= 0 && end.y < 8) {  // Stay inside the board
            Square* diagSquare = &squares[(int) end.x][(int) end.y];
            if (diagSquare->getPiece() != nullptr && diagSquare->getPiece()->getColor() != color) {
                validMoves.push_back(diagSquare);
            }
        }
    }

    return validMoves;
}

// Destructor
Pawn::~Pawn() {}
