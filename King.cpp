#include "King.h"
#include "Square.h"
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
        blackPieces.push_back(this);
        setTexture(King::blackKingTexture);
        color = 0;
    } else {
        if (!whiteKingTexture.loadFromFile("textures/Chess_klt60.png")) {
            std::cerr << "Error loading king texture" << std::endl;
        }
        whitePieces.push_back(this);
        setTexture(King::whiteKingTexture);
        color = 1;
    }
    name = "King";
}

bool King::isValidMove(const sf::Vector2f& end) const {
    // Return false if target coordinates outside of 8x8 (i.e < 0 or > 7)
    if (end.x < 0 || end.x > 7) { 
        return false;
    }
    if (end.y < 0 || end.y > 7) { 
        return false;
    }
    // Calculates absolute distance between start and end squares
    sf::Vector2f start = square->getGridPos();
    float dx = std::abs(end.x - start.x);
    float dy = std::abs(end.y - start.y);

    // King moves one square in any direction
    // i.e one or both of dx and dy = 1
    return (dx == 1 || dy == 1);
}

std::vector<Square*> King::getValidMoves(Square squares[8][8]) const {
    // Initialize valid moves vector
    std::vector<Square*> validMoves;
    // Get start coordinates
    sf::Vector2f start = square->getGridPos();
    // Double for loop to check each 8 directions (+x +y, +x 0y, +x -y etc)
    for (int x = 1; x >= -1; x--) {
        for (int y = 1; y >= -1; y--) {
             // Only run if x & y are not 0
            if (!((x == 0) && (y == 0))) {
                // Unit vector for direction
                sf::Vector2f direction(x, y);
                // One move per direction
                sf::Vector2f end = start + direction;
                if (isValidMove(end)) {
                    if (squares[(int) end.x][(int) end.y].getPiece() == nullptr) { // Check if square is free
                        // Needs check for friendly/enemy piece
                        validMoves.push_back(&squares[(int) end.x][(int) end.y]);
                    }
                }
            }
        }    
    }
    return validMoves;
}

// Destructor
King::~King() {}
