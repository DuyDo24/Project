#ifndef CLASS_H
#define CLASS_H

#include "Board.h"
#include "Player.h"

class Game {
    private:
        Board board;
        // Variable representing phase of the game
        // 0 - selecting card
        // 1 = selecting piece
        // 2 = selecting square
        int gamePhase;
        int playerTurn; //0 for black, 1 for white
        bool gameOver;
        std::vector<Player*> players;


        // Pointers to squares used in handleClick function
        Square* origin;
        Square* destination;
        //selected card piece
        Card* clickedCard;
    public:
        // Creates a default state game (starting position)
        Game();
        Game(sf::Font &font);
        // Creates a game from saved game state
        Game(sf::Font &font, bool saved);
        // Writes game state to file
        void saveGame();
        int getGamePhase();
        // Returns board
        Board* getBoard();
        Player* getPlayer(int color);
        
        int getPlayerTurn();
        void switchTurn(sf::Font &font);
        void setGamePhase(int phase);

        bool isGameOver() const;
        // Handles game logic when a click occurs to select and move pieces
        void handleClick(sf::RenderWindow& window, sf::Font& font);
        ~Game();
};

#endif