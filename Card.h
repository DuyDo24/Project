#ifndef CARD_H
#define CARD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Piece.h"  // Include your Piece class header

class Card {
    protected:
        Piece* piece;  // Pointer to the associated piece
        sf::RectangleShape cardShape; // Shape representing the card
        sf::Text cardText;          // Text displaying piece name or value
        sf::Sprite image;
        int pos; //position of cards in a line
        int color; // black = 0, white = 1;

    public:
        Card();
        Card(Piece *piece, const sf::Font& font, int pos); // Constructor to create a card with a piece
        void draw(sf::RenderWindow& window) const; // Method to draw the card
        Piece* getPiece() const; // Method to get the associated piece
        int getColor();
        ~Card();
};

#endif
