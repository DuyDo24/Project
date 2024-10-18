#include <iostream>
#include "Player.h"
#include "Piece.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Card.h"
#include "Board.h"
#include <SFML/Graphics.hpp>

class PlayerTest {
public:
    void runTests() {
        testPlayerParameterizedConstructor();
        testGenerateCards();
        testRemovePiece();
    }
    Board board;

private:
    void testPlayerParameterizedConstructor() {
        Player player(0);  // Create player with color 0 (black)

        if (player.getPieces().size() != 0) {
            std::cout << "Parameterized Constructor Test failed!" << std::endl;
        } else {
            std::cout << "Parameterized Constructor Test passed!" << std::endl;
        }
    }

    void testGenerateCards() {
        Player player(1);  // Create player with color 1 (white)
        sf::Font font;
        Pawn *pawn = new Pawn(board.getChessSquare(7, 1), true);
        Knight *knight = new Knight(board.getChessSquare(7, 2), true);
        Bishop *bishop = new Bishop(board.getChessSquare(7, 3), false);
        player.addPiece(pawn);
        player.addPiece(knight);
        player.addPiece(bishop);
        font.loadFromFile("arial.ttf");  // Ensure correct path to font

        player.generateCards(font);

        if (player.getPieces().size() == 3) {
            std::cout << "GenerateCards Test passed!" << std::endl;
        }
    }
          

    void testRemovePiece() {
        Player player(0);  // Create player with color 0 (black)
        Bishop bishop(board.getChessSquare(7, 3), false);
        player.addPiece(&bishop);  // Add a piece
        player.removePiece(&bishop);  // Remove the piece

        if (player.getPieces().size() == 0) {
            std::cout << "RemovePiece Test passed!" << std::endl;
        } else {
            std::cout << "RemovePiece Test failed!" << std::endl;
        }
    }
};
