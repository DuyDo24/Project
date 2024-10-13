#ifndef BOARD_H
#define BOARD_H
#include "Square.h"
#include <vector>

class Board {
    private:
        Square squares[8][8];
    public:
        // Constructs default chessboard
        Board();

        //-- Drawing --//

        // Draws each square in squares
        void drawBoard(sf::RenderWindow& window);
        // Sets highlight of each square to false
        void unhighlightAll();
        
        //-- Game logic --//

        // Returns pointer to chess square given two ints representing indices in squares
        Square* getChessSquare(int x, int y);
        // Returns pointer to chess square given a vector2 representing indices in squares
        Square* getChessSquare(sf::Vector2f gridPos);

        // Returns pointer to clicked square; returns nullptr if no square clicked
        Square* getClickedSquare(sf::RenderWindow& window);

        // Moves a piece from the origin square to the destination square
        void movePiece(Square* origin, Square* destination);

        // Returns whether a move from origin square to destination square is valid 
        bool checkValidMove(Square* origin, Square* destination);
        // Returns a vector of pointers to squares which are valid moves away from given origin square
        std::vector<Square*> getValidMoves(Square* origin);
};

#endif