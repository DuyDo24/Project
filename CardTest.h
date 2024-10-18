#include <iostream>
#include "Card.h"
#include "Piece.h"  // Assuming this is defined elsewhere
#include "Pawn.h"
#include "Board.h"
#include "Bishop.h"

class CardTest {
public:
    void runTests() {
        //testCardDefaultConstructor();
        testCardParameterizedConstructor();
        testSetHighlight();
    }
    Board board;

private:
    // void testCardDefaultConstructor() {
    //     Card card;

    //     if (card.getPiece() != nullptr) {
    //         std::cout << "Default Constructor Test failed!" << std::endl;
    //     } else {
    //         std::cout << "Default Constructor Test passed!" << std::endl;
    //     }
    // }

    void testCardParameterizedConstructor() {
        Pawn pawn(board.getChessSquare(7, 1), true);  // Assuming Piece has a default constructor
        sf::Font font;
        font.loadFromFile("arial.ttf");  // Make sure to have a valid path

        Card card(&pawn, font, 0);

        if (card.getPiece() != &pawn) {
            std::cout << "Parameterized Constructor Test failed!" << std::endl;
        } else {
            std::cout << "Parameterized Constructor Test passed!" << std::endl;
        }
    }

    void testSetHighlight() {
        Bishop bishop(board.getChessSquare(7, 1), false);
        sf::Font font;
        font.loadFromFile("arial.ttf");
        Card card(&bishop, font, 0);

        card.setHighlight(true);
        // Assuming there is a way to check if the highlight is set, you would add a condition here
        // If no way to check, just print something for now.
        sf::Color HighlightColor = sf::Color(255, 122, 122, 255);
        if(card.getHighlight() == HighlightColor){
            std::cout << "SetHighlight Test passed" << std::endl;
        } else {
            std::cout << "SetHighlight Test failed" << std::endl;
        }
    }
};
