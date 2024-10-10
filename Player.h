#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Card.h"
#include "Piece.h"  // Include your Piece class header

class Player {
private:
    std::vector<Piece*> availablePieces; // Player's available pieces
    std::vector<Piece*> capturedPieces;   // Player's captured pieces
    std::vector<Card*> hand;              // Player's hand of cards
    sf::Font font;                        // Font for displaying card text

public:
    Player(const sf::Font& font);         // Constructor
    ~Player();                             // Destructor to clean up

    void drawHand(sf::RenderWindow& window); // Draw the player's hand of cards
    void capturePiece(Piece* piece);      // Capture a piece
    void addPiece(Piece* piece);          // Add a piece to available pieces
    void removePiece(Piece* piece);       // Remove a piece from available pieces

    const std::vector<Piece*>& getAvailablePieces() const; // Accessor for available pieces
    const std::vector<Piece*>& getCapturedPieces() const;  // Accessor for captured pieces
};

#endif
