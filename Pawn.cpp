#include "Pawn.h"
#include <iostream>

sf::Texture Pawn::whitePawnTexture;
sf::Texture Pawn::blackPawnTexture;

Pawn::Pawn(Square* startingSquare, bool black)
    : Piece(startingSquare, 1) {
    // Set sprite based on color
    if (black == true) { 
        if (!blackPawnTexture.loadFromFile("textures/Chess_pdt60.png")) {
            std::cerr << "Error loading pawn texture" << std::endl;
        }
        setTexture(Pawn::blackPawnTexture);
    } else {
        if (!whitePawnTexture.loadFromFile("textures/Chess_plt60.png")) {
            std::cerr << "Error loading pawn texture" << std::endl;
        }
        setTexture(Pawn::whitePawnTexture);
    }
}

bool Pawn::isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const {
    float dx = std::abs(end.x - start.x);
    float dy = std::abs(end.y - start.y);

    if (dx == 0 && ((dy == 1) || (dy == 2 && !hasMoved))) {
        return true;
    }
    if (dx == 1 && dy == 1) {
        return true;
    }
    return false;
}