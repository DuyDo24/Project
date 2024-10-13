#include "Board.h"
#include <iostream>
#include "Knight.h"

// Constructs default chessboard
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

// Draws board by drawing each square
void Board::drawBoard(sf::RenderWindow& window) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            squares[i][j].draw(window);
        }
    }
}

// Sets all squares' highlights to false
void Board::unhighlightAll() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            squares[i][j].setHighlight(false);
        }
    }
}

// Returns pointer to chess square given two ints representing indices in squares
Square* Board::getChessSquare(int x, int y) {
    return &squares[x][y];
}

// Returns pointer to chess square given a vector2 representing indices in squares
Square* Board::getChessSquare(sf::Vector2f gridPos) {
    return &squares[(int) gridPos.x][(int) gridPos.y];
}

// Returns pointer to clicked square; returns nullptr if no square clicked
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

// Moves a piece from the origin square to the destination square
void Board::movePiece(Square* origin, Square* destination) {
    // Early return if nullptr given as argument
    if (origin == nullptr || destination == nullptr) {
        std::cerr << "Failed to move: null pointer given" << std::endl;
        return;
    }
    // Early return if origin and destination squares are the same
    if (origin == destination) {
        return;
    }
    // Only runs if origin square has a piece
    if (origin->getPiece() != nullptr) {
        Piece* movingPiece = origin->getPiece();
        // Set new pieces/squares
        destination->setPiece(movingPiece);
        movingPiece->setSquare(destination);
        origin->removePiece();
    }
}

// Returns whether a move from origin square to destination square is valid 
bool Board::checkValidMove(Square* origin, Square* destination) {
    // Set piece to be moved
    Piece* movingPiece = origin->getPiece();
    // Set end coordinates
    sf::Vector2f end = destination->getGridPos();
    
    return movingPiece->isValidMove(end);
}

// Returns a vector of pointers to squares which are valid moves away from given origin square
std::vector<Square*> Board::getValidMoves(Square* origin) {
    // Set piece to be moved
    Piece* movingPiece = origin->getPiece();
    // Get vector of valid squares using piece's valid move checker
    std::vector<Square*> validSquares = movingPiece->getValidMoves(squares);
    return validSquares;
}