#include "Queen.h"
#include "Square.h"
#include <iostream>

// Static texture to be shared by all Queen instances
sf::Texture Queen::whiteQueenTexture;
sf::Texture Queen::blackQueenTexture;

// Constructor
Queen::Queen(Square* startingSquare, bool black)
    : Piece(startingSquare, 9) // 9 is the value of the Queen
{
    if (black == true) { 
        if (!blackQueenTexture.loadFromFile("textures/Chess_qdt60.png")) {
            std::cerr << "Error loading queen texture" << std::endl;
        }
        blackPieces.push_back(this);
        setTexture(Queen::blackQueenTexture);
        color = 0;
    } else {
        if (!whiteQueenTexture.loadFromFile("textures/Chess_qlt60.png")) {
            std::cerr << "Error loading queen texture" << std::endl;
        }
        whitePieces.push_back(this);
        setTexture(Queen::whiteQueenTexture);
        color = 1;
    }
    name = "Queen";
}

bool Queen::isValidMove(const sf::Vector2f& end) const {
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

    // Queen can move like a Rook or Bishop (horizontally, vertically, or diagonally)
    return (dx == 0 || dy == 0) || (dx == dy);
}

std::vector<Square*> Queen::getValidMoves(Square squares[8][8]) const {
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
                    if (squares[(int) currentPosition.x][(int) currentPosition.y].getPiece()->getColor() != color) { // Adds square if occupied by enemy piece
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
Queen::~Queen() {}