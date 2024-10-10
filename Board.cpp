#include "Board.h"

Board::Board() {
    for (int i=0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            sf::Vector2f position(i*50, j*50);
            sf::RectangleShape* square = squares[i][j].getSquare();
            square->setPosition(position);
        }
    }

    //Create squares with alternating colours
    for (int i = 0; i < 8; i+=2) {
        for (int j = 0; j < 8; j+=2) {
            squares[i][j].setColor(sf::Color::White);
            squares[i+1][j+1].setColor(sf::Color::White);
        }
    }
}

void Board::drawBoard(sf::RenderWindow& window) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            sf::Vector2f position(i*50, j*50);
            squares[i][j].draw(position, window);
        }
    }
}

Square* Board::getChessSquare(int x, int y) {
    return &squares[x][y];
}