#include "Bishop.h"
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
        setTexture(Bishop::blackBishopTexture);
    } else {
        if (!whiteBishopTexture.loadFromFile("textures/Chess_blt60.png")) {
            std::cerr << "Error loading knight texture" << std::endl;
        }
        setTexture(Bishop::whiteBishopTexture);
    }

}

bool Bishop::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
    float dx = std::abs(end.x - start.x);
    float dy = std::abs(end.y - start.y);

    // Bishop moves diagonally, which means dx == dy
    return (dx == dy);
}


// Destructor
Bishop::~Bishop() {}
