#include "Queen.h"
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
        setTexture(Queen::blackQueenTexture);
    } else {
        if (!whiteQueenTexture.loadFromFile("textures/Chess_qlt60.png")) {
            std::cerr << "Error loading queen texture" << std::endl;
        }
        setTexture(Queen::whiteQueenTexture);
    }
}

bool Queen::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
    float dx = std::abs(end.x - start.x);
    float dy = std::abs(end.y - start.y);

    // Queen can move like a Rook or Bishop (horizontally, vertically, or diagonally)
    return (dx == 0 || dy == 0) || (dx == dy);
}

// Destructor
Queen::~Queen() {}
