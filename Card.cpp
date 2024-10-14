#include "Card.h"
#include <iostream>
#include <vector>
#include "Piece.h"

// Constructor to initialize the card with a piece
Card::Card() { };

Card::Card(Piece *pPiece, const sf::Font& font, int pos) {
    // Set up the card shape (size, color, etc.)
    this->piece = pPiece;
    this->pos = pos;
    cardShape.setSize(sf::Vector2f(100, 150)); // Set size of the card
    color = piece->getColor();
    if(color == 0) {
        cardShape.setFillColor(sf::Color::White);  // White background
    } else {
        cardShape.setFillColor(sf::Color::Black);
    }
    cardShape.setPosition(0+(pos*100),400);

    // Set up card text
    cardText.setFont(font);
    cardText.setString(piece->getName());
    cardText.setCharacterSize(24);
    if(color == 0) {
        cardText.setFillColor(sf::Color::White);
    } else {
        cardText.setFillColor(sf::Color::Black);
    }
    cardText.setPosition(cardShape.getPosition().x + 10, cardShape.getPosition().y + 10); // Offset for padding
    image = piece->getImage();
    image.setPosition(cardShape.getPosition().x+50,cardShape.getPosition().y+50);
}

// Method to draw the card
void Card::draw(sf::RenderWindow& window) const {
    window.draw(cardShape);
    window.draw(cardText);
    window.draw(image);
}

// Method to get the associated piece
Piece* Card::getPiece() const {
    return piece;
}

int Card::getColor() {
    return color;
}

Card::~Card() {};