#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Pawn.h"
#include "Game.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include <vector>
int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "CARD CHESS");

    Game game;
    
    Board* board = game.getBoard();

    Rook br1(board->getChessSquare(0, 0), true);
    Knight bn1(board->getChessSquare(1, 0), true);
    Bishop bb1 (board->getChessSquare(2, 0), true);
    Queen bq1(board->getChessSquare(3, 0), true);
    King bk1(board->getChessSquare(4, 0), true);
    Bishop bb2(board->getChessSquare(5, 0), true);
    Knight bn2(board->getChessSquare(6, 0), true);
    Rook br2(board->getChessSquare(7, 0), true);
    Pawn bp1(board->getChessSquare(0, 1), false);
    Pawn bp2(board->getChessSquare(1, 1), false);
    Pawn bp3(board->getChessSquare(2, 1), false);
    Pawn bp4(board->getChessSquare(3, 1), false);
    Pawn bp5(board->getChessSquare(4, 1), false);
    Pawn bp6(board->getChessSquare(5, 1), false);
    Pawn bp7(board->getChessSquare(6, 1), false);
    Pawn bp8(board->getChessSquare(7, 1), false);

    Rook wr1(board->getChessSquare(0, 7), false);
    Knight wn1(board->getChessSquare(1, 7), false);
    Bishop wb1 (board->getChessSquare(2, 7), false);
    Queen wq1(board->getChessSquare(3, 7), false);
    King wk1(board->getChessSquare(4, 7), false);
    Bishop wb2(board->getChessSquare(5, 7), false);
    Knight wn2(board->getChessSquare(6, 7), false);
    Rook wr2(board->getChessSquare(7, 7), false);
    Pawn wp1(board->getChessSquare(0, 6), true);
    Pawn wp2(board->getChessSquare(1, 6), true);
    Pawn wp3(board->getChessSquare(2, 6), true);
    Pawn wp4(board->getChessSquare(3, 6), true);
    Pawn wp5(board->getChessSquare(4, 6), true);
    Pawn wp6(board->getChessSquare(5, 6), true);
    Pawn wp7(board->getChessSquare(6, 6), true);
    Pawn wp8(board->getChessSquare(7, 6), true);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {

                game.handleClick(window);
    
            }
        }

       window.clear(sf::Color(135, 206, 250)); // Custom background color

        // Draw the board centered in the window with the calculated offsets
        board->drawBoard(window); // Modify the drawBoard function to accept offsets

        window.display();
        
    }
    return 0;
}