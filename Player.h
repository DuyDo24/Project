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
        int color; //player's piece color (0 black, 1 white)
    public:
        Player(int color); //initialiser with players color
        Player();
        void generateCards(sf::Font &font);  //function to generate 3 cards with the current available pieces
        void drawCards(sf::RenderWindow& window);//function to draw all cards
        Card* getClickedCard(sf::RenderWindow& window);
        void removePiece(Piece *piece); //function to remove a piece
        void addPiece(Piece *piece); //function to add a piece
        std::vector<Square*> getValidPieceSquares(Piece *piece);
        std::vector<Piece*> getPieces();
        std::vector<Piece*> getCapturedPieces();
        void capturePiece(Piece *piece, Player *opponent); //function to capture an opponents piece
        ~Player();
};

#endif