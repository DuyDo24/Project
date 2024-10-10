#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Pawn.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    Board board;

    Pawn pawn(board.getChessSquare(1, 1));
    Pawn pawn2(board.getChessSquare(2, 1));
    Pawn pawn3(board.getChessSquare(3, 1));
    Pawn pawn4(board.getChessSquare(4, 1));

    sf::Image image;

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
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // sf::Vector2f pos(100,100);
        // s1.setColor(sf::Color::White);
        // s1.draw(pos, window);

        //window.draw(square);

        board.drawBoard(window);
        pawn.draw(window);
        pawn2.draw(window);
        pawn3.draw(window);
        pawn4.draw(window);

        window.display();
    }

    return 0;
}