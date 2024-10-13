#include "Knight.h"
#include "Square.h"
#include <iostream>

// Static texture to be shared by all Knight instances
sf::Texture Knight::whiteKnightTexture;
sf::Texture Knight::blackKnightTexture;

// Constructor
Knight::Knight(Square* startingSquare, bool black)
    : Piece(startingSquare, 3) // 3 is the value of the Knight
{
    if (black == true) { 
        if (!blackKnightTexture.loadFromFile("textures/Chess_ndt60.png")) {
            std::cerr << "Error loading knight texture" << std::endl;
        }
        blackPieces.push_back(this);
        setTexture(Knight::blackKnightTexture);
        color = 0;
    } else {
        if (!whiteKnightTexture.loadFromFile("textures/Chess_nlt60.png")) {
            std::cerr << "Error loading knight texture" << std::endl;
        }
        whitePieces.push_back(this);
        setTexture(Knight::whiteKnightTexture);
        color = 1;
    }
    name = "Knight";

}

// Returns move validity given integer start and end coordinates
bool Knight::isValidMove(const sf::Vector2f& end) const {
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

std::vector<Square*> Knight::getValidMoves(Square squares[8][8]) const {
    // Initialize valid moves vector
    std::vector<Square*> validMoves;
    // Get start coordinates
    sf::Vector2f start = square->getGridPos();
    // Double for loop to check each quadrant (+x +y, +x -y etc)
    for (int x = 1; x >= -1; x -= 2) {
        for (int y = 1; y >= -1; y -= 2) {
            // Two moves per quadrant
            // 2 squares x, 1 square y
            sf::Vector2f end = start + sf::Vector2f(2*x, y);
            if (isValidMove(end)) {
                if (squares[(int) end.x][(int) end.y].getPiece() == nullptr) { // Check if square is free
                // Needs check for friendly/enemy piece
                    validMoves.push_back(&squares[(int) end.x][(int) end.y]);
                }
            }
            // 1 square x, 2 squares y
            end = start + sf::Vector2f(x, 2*y);
            if (isValidMove(end)) {
                if (squares[(int) end.x][(int) end.y].getPiece() == nullptr) { // Check if square is free
                // Needs check for friendly/enemy piece
                    validMoves.push_back(&squares[(int) end.x][(int) end.y]);
                }
            }
        }    
    }
    return validMoves;
}

// Destructor
Knight::~Knight() {}