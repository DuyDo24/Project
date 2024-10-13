#include "Knight.h"
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
bool Knight::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
    // Calculates absolute distance between start and end squares
    // Absolute distance can be used as the knight is directionally agnostic and it can move through pieces
    // which means no checks are needed for blocking pieces
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

// Destructor
Knight::~Knight() {}