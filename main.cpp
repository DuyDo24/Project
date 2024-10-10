#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Square.h"
#include "Pawn.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "King.h"


int main() {
    // Create a window for the game
    sf::RenderWindow window(sf::VideoMode(400, 400), "Card Chess - Display Pawn");
    Board board;

    Pawn wpawn1(board.getChessSquare(0,6));
    Pawn wpawn2(board.getChessSquare(1, 6));
    Pawn wpawn3(board.getChessSquare(2, 6));
    Pawn wpawn4(board.getChessSquare(3, 6));
    Pawn wpawn5(board.getChessSquare(4, 6));
    Pawn wpawn6(board.getChessSquare(6, 6));
    Pawn wpawn7(board.getChessSquare(7, 6));
    Pawn wpawn8(board.getChessSquare(5, 6));
    Queen wqueen(board.getChessSquare(3, 7));
    Bishop wbishop1(board.getChessSquare(2,7));
    Bishop wbishop2(board.getChessSquare(5,7));
    Knight wknight1(board.getChessSquare(6,7));
    Knight wknight2(board.getChessSquare(1,7));
    Rook wrook1(board.getChessSquare(0, 7));
    Rook wrook2(board.getChessSquare(7, 7));
    King wking(board.getChessSquare(4, 7));
    
    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear(sf::Color::Black);

        // Draw the pawn
        board.drawBoard(window);
        wpawn1.draw(window); 
        wpawn2.draw(window); 
        wpawn3.draw(window); 
        wpawn4.draw(window); 
        wpawn5.draw(window); 
        wpawn6.draw(window); 
        wpawn7.draw(window); 
        wpawn8.draw(window); 
        wqueen.draw(window);
        wbishop1.draw(window);
        wknight1.draw(window);
        wrook1.draw(window);
        wbishop2.draw(window);
        wknight2.draw(window);
        wrook2.draw(window);
        wking.draw(window);
       // Call the draw method of the Pawn class

        // Display everything on the window
        window.display();
    }

    return 0;
}