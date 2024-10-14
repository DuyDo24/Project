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
        cardShape.setFillColor(sf::Color::White);  // If piece is black, White background
    } else {
        cardShape.setFillColor(sf::Color::Black); //if piece is white, black background
    }
    cardShape.setPosition(10+(pos*110),410); //setting position below board, x value depending on position (order) of card

    // Set up card text
    cardText.setFont(font);
    cardText.setString(piece->getName()); //getting name of piece
    cardText.setCharacterSize(18);
    if(color == 0) {
        cardText.setFillColor(sf::Color::Black); //if piece is black, black text
    } else {
        cardText.setFillColor(sf::Color::White); // if piece is white, white text
    }
    cardText.setPosition(cardShape.getPosition().x + 50 - ((cardText.getLocalBounds().width)/2), cardShape.getPosition().y + 15); // setting text to the middle of the card in terms of width
    image = piece->getImage(); //getting image from the piece
    image.setPosition(cardShape.getPosition().x+25,cardShape.getPosition().y+50); //setting position to the centre of the card
}

// Method to draw the card
void Card::draw(sf::RenderWindow& window) {
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