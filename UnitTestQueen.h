#include <iostream>
#include "Piece.h"
#include "Queen.h"
#include "Square.h"

class UnitTest {
public:
    void runTests() {
        testQueenValidMove();
        testQueenValidMoves();
    }

private:
    void testQueenValidMove() {
        Square startingSquare;
        Queen queen(&startingSquare, false);  // White Queen

        if (!queen.isValidMove(sf::Vector2f(0, 7))) {
            std::cout << "Test Queen Valid Move (Vertical) failed!" << std::endl;
        }
        if (!queen.isValidMove(sf::Vector2f(7, 0))) {
            std::cout << "Test Queen Valid Move (Horizontal) failed!" << std::endl;
        }
        if (!queen.isValidMove(sf::Vector2f(7, 7))) {
            std::cout << "Test Queen Valid Move (Diagonal) failed!" << std::endl;
        }
        if (queen.isValidMove(sf::Vector2f(3, 5))) {
            std::cout << "Test Queen Invalid Move failed!" << std::endl;
        }
    }

    void testQueenValidMoves() {
        // Set up an 8x8 board with Square objects (not pointers)
        Square board[8][8];
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                sf::Vector2f gridPos(i, j);
                board[i][j].setGridPos(gridPos);
                board[i][j].setPosition(sf::Vector2f(i * 50, j * 50));  // Set position for testing
            }
        }

        Square startingSquare;
        Queen queen(&startingSquare, false);  // White Queen

        std::vector<Square*> validMoves = queen.getValidMoves(board);

        if (validMoves.size() != 21) {
            std::cout << "Test Queen Get Valid Moves failed! Expected 21, got " << validMoves.size() << std::endl;
        } else {
            std::cout << "Queen works perfectly being able to move in every direction" <<std::endl;
        }
    }
};
