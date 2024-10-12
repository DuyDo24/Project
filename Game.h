#ifndef CLASS_H
#define CLASS_H

#include "Board.h"

class Game {
    private:
        Board board;
        // 0 = selecting piece
        // 1 = selecting square
        int gamePhase;
        Square* origin; 
        Square* destination;
    public:
        Game();
        Board* getBoard();
        // Handles game logic when a click occurs
        void handleClick(sf::RenderWindow& window);
};

#endif