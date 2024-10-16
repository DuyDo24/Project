#include "Bishop.h"
#include "Square.h"
#include <iostream>

// Static texture to be shared by all Bishop instances
sf::Texture Bishop::blackBishopTexture;
sf::Texture Bishop::whiteBishopTexture;

// Constructor
Bishop::Bishop(Square* startingSquare, bool black)
    : Piece(startingSquare, 3) // 3 is the value of the Bishop
{
    if (black == true) { 
        if (!blackBishopTexture.loadFromFile("textures/Chess_bdt60.png")) {
            std::cerr << "Error loading knight texture" << std::endl;
        }
        blackPieces.push_back(this);
        setTexture(Bishop::blackBishopTexture);
        color = 0;
    } else {
        if (!whiteBishopTexture.loadFromFile("textures/Chess_blt60.png")) {
            std::cerr << "Error loading knight texture" << std::endl;
        }
        whitePieces.push_back(this);
        setTexture(Bishop::whiteBishopTexture);
        color = 1;
    }
    name = "Bishop";
}

bool Bishop::isValidMove(const sf::Vector2f& end) const {
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

    // Bishop moves diagonally, which means dx == dy
    return (dx == dy);
}

std::vector<Square*> Bishop::getValidMoves(Square squares[8][8]) const {
    // Initialize valid moves vector
    std::vector<Square*> validMoves;
    // Get start coordinates
    sf::Vector2f start = square->getGridPos();
    // Double for loop to check each quadrant/diagonal (+x +y, +x -y etc)
    for (int x = 1; x >= -1; x -= 2) {
        for (int y = 1; y >= -1; y -= 2) {
            // Create unit vector for direction
            sf::Vector2f direction(x, y);
            // For each quadrant, the diagonal line of squares is checked
            // Set current position to diagonally adjacent square
            sf::Vector2f currentPosition = start + direction;
            
            // Loop conditions
            bool outsideBoard = false;
            bool blocked = false;
            if (currentPosition.x < 0 || currentPosition.x > 7 || currentPosition.y < 0 || currentPosition.y > 7) { // Check if first square is outside board
                outsideBoard = true;
            } else if (squares[(int) currentPosition.x][(int) currentPosition.y].getPiece() != nullptr) { // Check if first square is occupied
                blocked = true;
                if (squares[(int) currentPosition.x][(int) currentPosition.y].getPiece()->getColor() != color) { // Adds square if occupied by enemy piece
                    validMoves.push_back(&squares[(int) currentPosition.x][(int) currentPosition.y]);
                }
            }

            // Loop to go through each square of the diagonal
            while (!outsideBoard && !blocked) {
                // Add square if valid
                if (isValidMove(currentPosition)) {
                    validMoves.push_back(&squares[(int) currentPosition.x][(int) currentPosition.y]);
                }
                // Set next square in diagonal
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
    return validMoves;
}

// Destructor
Bishop::~Bishop() {}
