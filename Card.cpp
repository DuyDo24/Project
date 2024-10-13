#include "Card.h"

// Constructor to initialize the card with a piece
Card::Card(Piece* pPiece, const sf::Font& font, int pos) : piece(pPiece) , pos(pos) {
    // Set up the card shape (size, color, etc.)
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
}

// Method to draw the card
void Card::draw(sf::RenderWindow& window) const {
    window.draw(cardShape);
    window.draw(cardText);
}

// Method to get the associated piece
Piece* Card::getPiece() const {
    return piece;
}

std::vector<Piece*> Card::getavailPieces(std::vector<Piece*> visiblePieces) {
    int visSize = visiblePieces.size();
    std::vector<Piece*> availPiecesNew;
    int availSize;
    bool found = false;
    for(int i=0;i<visSize;i++) {
        found = false;
        availSize = availPiecesNew.size();
        for(int j=0;j<availSize;j++) {
            if(visiblePieces[i]->getName() == availPiecesNew[j]->getName()) {
                found = true;
            }
        }
        if(!found) {
            availPiecesNew.push_back(visiblePieces[i]);
        }
    }
    return availPiecesNew;
}