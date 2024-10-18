// UnitTestRook.h

#include <iostream>
#include "Rook.h"
#include "Square.h"

class UnitTestRook {
public:
    void runTests() {
        testIsValidMove();
        testGetValidMoves();
    }

private:
    void testIsValidMove() {
        Square startingSquare;
        startingSquare.setGridPos(sf::Vector2f(0,0)); // Set position to 0,0
        Rook rook(&startingSquare, true); // Create a white rook

        // Valid moves for a rook (horizontal or vertical)
        sf::Vector2f validMove1(0, 5);   // Valid vertical move
        sf::Vector2f validMove2(5, 0);   // Valid horizontal move
        sf::Vector2f invalidMove1(1, 1); // Invalid diagonal move
        sf::Vector2f invalidMove2(0, 9); // Invalid out-of-bounds move
        bool testsPassed = true;
        if (!rook.isValidMove(validMove1)) {
            std::cout << "testIsValidMove failed: (0, 5) should be valid!" << std::endl;
            testsPassed = false;
        }
        if (!rook.isValidMove(validMove2)) {
            std::cout << "testIsValidMove failed: (5, 0) should be valid!" << std::endl;
            testsPassed = false;
        }
        if (rook.isValidMove(invalidMove1)) {
            std::cout << "testIsValidMove failed: (1, 1) should be invalid!" << std::endl;
            testsPassed = false;
        }
        if (rook.isValidMove(invalidMove2)) {
            std::cout << "testIsValidMove failed: (0, 9) should be invalid!" << std::endl;
            testsPassed = false;
        }
        if (testsPassed) {
            std::cout << "All tests for isValidMove() passed" << std::endl;
        }
    }

    void testGetValidMoves() {
        Square squares[8][8];
        Square startingSquare; // Starting position of the rook
        Rook rook(&startingSquare, true); // Create a white rook

        // Set up the board with some valid and invalid positions
        // Assume we are at position (4, 4) on an 8x8 board
        sf::Vector2f rookPosition(4, 4);
        startingSquare.setGridPos(rookPosition);

        // Mark valid moves: vertical and horizontal paths
        std::vector<Square*> validMoves = rook.getValidMoves(squares);

        // Expect valid moves (4,0) to (4,7) and (0,4) to (7,4) without obstruction
        int expectedMoves = 14; // 7 vertical + 7 horizontal

        if (validMoves.size() != expectedMoves) {
            std::cout << "testGetValidMoves failed! Expected " << expectedMoves << " valid moves." << std::endl;
        }

        // You can also add specific checks for certain positions in validMoves if needed
        // For example, checking if specific squares are included
    }
};
