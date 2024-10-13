#ifndef BOARD_H
#define BOARD_H
#include "Square.h"
#include <vector>

class Board {
    private:
        Square squares[8][8];
    public:
        Board();
        //-- Drawing --//
        void drawBoard(sf::RenderWindow& window);
        void unhighlightAll();
        
        //-- Game logic --//
        Square* getChessSquare(int x, int y);
        Square* getClickedSquare(sf::RenderWindow& window);
        void movePiece(Square* origin, Square* destination);

        // Return vector of pointers to squares that are valid moves from the origin
        std::vector<Square*> getValidMoves(Square* origin);
        // Return move validity given two squares
        bool checkValidMove(Square* origin, Square* destination);
        
};

#endif