#include "Rook.h"
#include "Square.h"
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
            std::cerr << "Error loading Rook texture" << std::endl;
        }
        blackPieces.push_back(this);
        setTexture(Rook::blackRookTexture);
        color = 0;
    } else {
        if (!whiteRookTexture.loadFromFile("textures/Chess_rlt60.png")) {
            std::cerr << "Error loading Rook texture" << std::endl;
        }
        whitePieces.push_back(this);
        setTexture(Rook::whiteRookTexture);
        color = 1;
    }
    name = "Rook";
}

bool Rook::isValidMove(const sf::Vector2f& end) const {
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

    // Rook moves either in a straight line horizontally or vertically
    return (dx == 0 || dy == 0);
}

std::vector<Square*> Rook::getValidMoves(Square squares[8][8]) const {
    // Initialize valid moves vector
    std::vector<Square*> validMoves;
    // Get start coordinates
    sf::Vector2f start = square->getGridPos();
    // Double for loop to check each 8 directions (+x +y, +x 0y, +x -y etc)
    for (int x = 1; x >= -1; x--) {
        for (int y = 1; y >= -1; y--) {
            if ((x == 0 && y != 0) || (x != 0 && y == 0)) { // Only run if exclusively 1 of x and y are 0
                // Unit vector for direction
                sf::Vector2f direction(x, y);
                // For each direction, the line of squares is checked
                // Set current position to directionally adjacent square
                sf::Vector2f currentPosition = start + direction;
                
                bool outsideBoard = false;
                bool blocked = false;
                // Check if first square is outside board
                if (currentPosition.x < 0 || currentPosition.x > 7 || currentPosition.y < 0 || currentPosition.y > 7) {
                    outsideBoard = true;
                } else if (squares[(int) currentPosition.x][(int) currentPosition.y].getPiece() != nullptr) { // Check if first square is occupied
                    blocked = true;
                    if (squares[(int) currentPosition.x][(int) currentPosition.y].getPiece()->getColor() != color) {// Adds square if occupied by enemy piece
                        validMoves.push_back(&squares[(int) currentPosition.x][(int) currentPosition.y]);
                    }
                }

                // Loop to go through each square of the line
                while (!outsideBoard && !blocked) {
                    // Add square if valid
                    if (isValidMove(currentPosition)) {
                        validMoves.push_back(&squares[(int) currentPosition.x][(int) currentPosition.y]);
                    }
                    // Set next square in direction
                    sf::Vector2f newPosition = currentPosition + direction;
                    // Check if next square is outside the board
                    if (newPosition.x < 0 || newPosition.x > 7 || newPosition.y < 0 || newPosition.y > 7) {
                        outsideBoard = true;
                    } else if (squares[(int) newPosition.x][(int) newPosition.y].getPiece() != nullptr) { // Check if next square is occupied
                        blocked = true;
                        if (squares[(int) newPosition.x][(int) newPosition.y].getPiece()->getColor() != color) { // Adds square if occupied by enemy piece
                            validMoves.push_back(&squares[(int) newPosition.x][(int) newPosition.y]);
                        }
                    }

                    currentPosition = newPosition;
                }
            }
        }    
    }
    return validMoves;
}

// Destructor
Rook::~Rook() {}
