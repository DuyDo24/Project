#include "Card.h"

// Constructor to initialize the card with a piece
Card::Card(Piece* pPiece, const sf::Font& font) : piece(pPiece) {
    // Set up the card shape (size, color, etc.)
    cardShape.setSize(sf::Vector2f(100, 150)); // Set size of the card
    cardShape.setFillColor(sf::Color::White);  // White background

    // Set up card text
    cardText.setFont(font);
    cardText.setString("Piece: " + std::to_string(piece->getValue())); // Or piece->getName() if you implement it
    cardText.setCharacterSize(24);
    cardText.setFillColor(sf::Color::Black);
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

// Static method to get available uncaptured pieces (implement your logic here)
std::vector<Piece*> Card::getAvailablePieces() {
    static std::vector<Piece*> availablePieces;
    // Logic to populate availablePieces with uncaptured pieces
    // This is just a placeholder; you need to fill this with actual pieces

    // Example (create and add pieces):
    // sf::Texture texture; // Load your piece textures here
    // availablePieces.push_back(new Pawn(sf::Vector2f(0, 0), nullptr, texture)); // Replace with actual starting square and texture

    return availablePieces;
}
