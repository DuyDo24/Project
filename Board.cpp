#include "Board.h"
#include <iostream>
#include "Knight.h"

Board::Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            sf::Vector2f position(i*50, j*50);
            sf::Vector2f gridPos(i, j);
            squares[i][j].setPosition(position);
            squares[i][j].setGridPos(gridPos);
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
            squares[i][j].draw(window);
        }
    }
}

void Board::unhighlightAll() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            squares[i][j].setHighlight(false);
        }
    }
}

Square* Board::getChessSquare(int x, int y) {
    return &squares[x][y];
}

Square* Board::getClickedSquare(sf::RenderWindow& window) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (squares[i][j].checkClicked(window)) {
                return &squares[i][j];
            }
        }
    }
    return nullptr;
}

void Board::movePiece(Square* origin, Square* destination) {
    if (origin == nullptr || destination == nullptr) {
        std::cerr << "Failed to move: null pointer given" << std::endl;
        return;
    }
    if (origin == destination) {
        return;
    }
    if (origin->getPiece() != nullptr) {
        Piece* movingPiece = origin->getPiece();
        // Set new piece/square
        destination->setPiece(movingPiece);
        movingPiece->setSquare(destination);
        origin->removePiece();
    }
}

bool Board::checkValidMove(Square* origin, Square* destination) {
    // Set piece to be moved
    Piece* movingPiece = origin->getPiece();
    // Set end coordinates
    sf::Vector2f end = destination->getGridPos();
    
    return movingPiece->isValidMove(end);
}

std::vector<Square*> Board::getValidMoves(Square* origin) {
    // Set piece to be moved
    Piece* movingPiece = origin->getPiece();
    // Get vector of valid squares
    std::vector<Square*> validSquares = movingPiece->getValidMoves(squares);
    return validSquares;
}