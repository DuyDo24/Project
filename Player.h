#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>
#include "Piece.h"

class Player {
    protected:
        std::vector<Piece*> pieces; //vector of player's current pieces on the board
        std::vector<Piece*> capturedPieces; //vector of player's captured pieces
        std::vector<Card*> hand; //players current hand of cards
        int color; //player's piece color
    public:
        Player(int color); //initialiser with players color
        void generateCards(sf::Font &font);  //function to generate 3 cards with the current available pieces
        void drawCards(sf::RenderWindow& window);//function to draw all cards
        void removePiece(Piece *piece); //function to remove a piece
        void addPiece(Piece *piece); //function to add a piece
        void capturePiece(Piece *piece, Player *opponent); //function to capture an opponents piece
};

#endif