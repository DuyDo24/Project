#include "Bishop.h"
#include <iostream>

// Static texture to be shared by all Bishop instances
sf::Texture Bishop::bishopTexture;

// Constructor
Bishop::Bishop(Square* startingSquare)
    : Piece(startingSquare, 3) // 3 is the value of the Bishop
{

    if (!bishopTexture.loadFromFile("textures/Chess_blt60.png")) {
        std::cerr << "Error loading pawn texture" << std::endl;
    }
    setTexture(bishopTexture);
}

bool Bishop::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
  
}

// Destructor
Bishop::~Bishop() {}
