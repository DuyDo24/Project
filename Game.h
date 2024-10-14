#ifndef CLASS_H
#define CLASS_H

#include "Board.h"
#include "Player.h"

class Game {
    private:
        Board board;
        // Variable representing phase of the game
        // 0 = selecting piece
        // 1 = selecting square
        int gamePhase;
        Player *playerWhite;
        Player *playerBlack;

        // Pointers to squares used in handleClick function
        Square* origin;
        Square* destination;
    public:
        // Creates a default state game (starting position)
        Game();
        // Returns board
        Board* getBoard();
        Player* getPlayer(int color);
        
        // Handles game logic when a click occurs to select and move pieces
        void handleClick(sf::RenderWindow& window);
        ~Game();
};

#endif