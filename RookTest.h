#include <iostream>
#include "Rook.h"
#include "Square.h"

class RookTest {
public:
    void runTests() {
        testRookConstructor();
        testRookValidMove();
        testRookValidMoves();
    }

private:
    void testRookConstructor() {
        Square startingSquare;
        Rook rook(&startingSquare, false);  // White Rook

        if (rook.getValue() != 5) {  // Rook has a value of 5
            std::cout << "Test Rook Constructor: Value initialization failed!" << std::endl;
        }

        if (rook.getSquare() != &startingSquare) {
            std::cout << "Test Rook Constructor: Square initialization failed!" << std::endl;
        }

        if (rook.getName() != "Rook") {
            std::cout << "Test Rook Constructor: Name initialization failed!" << std::endl;
        }
    }

    void testRookValidMove() {
        Square startingSquare;
        Rook rook(&startingSquare, false);  // White Rook

        // Test vertical move
        if (!rook.isValidMove(sf::Vector2f(0, 7))) {
            std::cout << "Test Rook Valid Move (Vertical) failed!" << std::endl;
        }

        // Test horizontal move
        if (!rook.isValidMove(sf::Vector2f(7, 0))) {
            std::cout << "Test Rook Valid Move (Horizontal) failed!" << std::endl;
        }

        // Test diagonal move (should be invalid for Rook)
        if (rook.isValidMove(sf::Vector2f(7, 7))) {
            std::cout << "Test Rook Invalid Move (Diagonal) failed!" << std::endl;
        }

        // Test invalid move (L-shaped move like a knight)
        if (rook.isValidMove(sf::Vector2f(2, 1))) {
            std::cout << "Test Rook Invalid Move (L-shape) failed!" << std::endl;
        }
    }

    void testRookValidMoves() {
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
        Rook rook(&startingSquare, false);  // White Rook

        std::vector<Square*> validMoves = rook.getValidMoves(board);

        // In an open board, a Rook at position (0, 0) should have 14 valid moves (7 horizontal, 7 vertical)
        if (validMoves.size() != 14) {
            std::cout << "Test Rook Get Valid Moves failed! Expected 14, got " << validMoves.size() << std::endl;
        } else {
            std::cout << "Rook works Perfectily being able to move in straight lines only" << std::endl;
        }
    }
};