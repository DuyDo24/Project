#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Game.h"
#include "Player.h"
#include "Card.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");

    Player playerBlack(0);
    Player playerWhite(1);

    Game game(&playerWhite,&playerBlack);

    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    Board* board = game.getBoard();

    // Testing adding pieces to board
    // Pawn pawn(board->getChessSquare(1, 6), true);
    // Pawn pawn2(board->getChessSquare(2, 6), false);
    // Pawn pawn3(board->getChessSquare(3, 6), true);
    // Pawn pawn4(board->getChessSquare(4, 6), false);
    // Works

    //Knight n1(board->getChessSquare(3,1), true);

    //Bishop b1(board->getChessSquare(1,1), true);

    //King k1(board->getChessSquare(2,1), true);

    //Queen q1(board->getChessSquare(4,1), true);
    
    //Rook r1(board->getChessSquare(5,1), true);

    playerWhite.generateCards(font);
    //Square s1;

    // sf::RectangleShape square;
    // square.setFillColor(sf::Color::White);
    // square.setSize(sf::Vector2f(100,100));
    // square.setPosition(sf::Vector2f(100,100));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::A) {
                    board->movePiece(board->getChessSquare(1,1), board->getChessSquare(1,2));
                } else {
                    board->movePiece(board->getChessSquare(1,2), board->getChessSquare(1,1));
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                // Testing square click detection
                // if (board.getChessSquare(1,1)->checkClicked(window)) {
                //     board.movePiece(board.getChessSquare(1,1), board.getChessSquare(1,2));
                //     }
                // Works

                // Testing board.getClickedSquare()
                // board.movePiece(board.getClickedSquare(window), board.getChessSquare(4,4));
                // Works

                // Testing board getClickedSquare + two-step moving (choosing piece and target)
                game.handleClick(window);
                // Works

                // Testing square highlighting
                // board->getClickedSquare(window)->setHighlight(true);
                // Works
            }
        }

        window.clear(sf::Color(135, 206, 250));

        // sf::Vector2f pos(100,100);
        // s1.setColor(sf::Color::White);
        // s1.draw(pos, window);

        //window.draw(square);
        playerWhite.drawCards(window);
        board->drawBoard(window);
        
        // pawn.draw(window);
        // pawn2.draw(window);
        // pawn3.draw(window);
        // pawn4.draw(window);

        window.display();
        
    }
    return 0;
}