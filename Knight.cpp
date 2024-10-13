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

std::vector<Square*> Knight::getValidMoves(Square squares[8][8]) const {
    std::vector<Square*> validMoves;
    sf::Vector2f start = square->getGridPos();
    // Double for loop to check each quadrant (+x +y, +x -y etc)
    for (int i = 1; i >= -1; i -= 2) {
        for (int j = 1; j >= -1; j -= 2) {
            // Two moves per quadrant
            // 2x 1y
            sf::Vector2f end = start + sf::Vector2f(2*i, j);
            if (isValidMove(end)) {
                int x = end.x;
                int y = end.y;
                validMoves.push_back(&squares[x][y]);
            }
            // 1x 2y
            end = start + sf::Vector2f(i, 2*j);
            if (isValidMove(end)) {
                int x = end.x;
                int y = end.y;
                validMoves.push_back(&squares[x][y]);
            }
        }    
    }
    return validMoves;
}

// Destructor
Knight::~Knight() {}