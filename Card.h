#ifndef CARD_H
#define CARD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Piece.h"  // Include your Piece class header

class Card {
private:
    Piece* piece;  // Pointer to the associated piece
    sf::RectangleShape cardShape; // Shape representing the card
    sf::Text cardText;            // Text displaying piece name or value

public:
    Card(Piece* piece, const sf::Font& font); // Constructor to create a card with a piece

    void draw(sf::RenderWindow& window) const; // Method to draw the card
    Piece* getPiece() const; // Method to get the associated piece

    static std::vector<Piece*> getAvailablePieces(); // Static method to get available uncaptured pieces
};

#endif
