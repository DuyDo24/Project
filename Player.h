#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>
#include "Piece.h"

class Player {
    protected:
        std::vector<Piece*> pieces;
        std::vector<Piece*> capturedPieces;
        std::vector<Card*> hand;
        int color;
    public:
        Player(int color);
        void generateCards(std::vector<Piece*> pieces, sf::Font &font);
        void drawCards(sf::RenderWindow& window);
        void removePiece(Piece *piece);
        void addPiece(Piece *piece);
        void capturePiece(Piece *piece, Player *opponent);
};

#endif