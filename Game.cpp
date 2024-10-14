#include "Game.h"
#include <algorithm>
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include <iostream>

// Creates a default state game (starting position)
Game::Game() {
    gamePhase = 0;

    playerBlack = new Player(0);
    playerWhite = new Player(1);


    playerBlack->addPiece(new Rook(board.getChessSquare(0, 0), true));
    playerBlack->addPiece(new Knight(board.getChessSquare(1, 0), true));
    playerBlack->addPiece(new Bishop(board.getChessSquare(2, 0), true));
    playerBlack->addPiece(new Queen(board.getChessSquare(3, 0), true));
    playerBlack->addPiece(new King(board.getChessSquare(4, 0), true));
    playerBlack->addPiece(new Bishop(board.getChessSquare(5, 0), true));
    playerBlack->addPiece(new Knight(board.getChessSquare(6, 0), true));
    playerBlack->addPiece(new Rook(board.getChessSquare(7, 0), true));
    
    playerBlack->addPiece(new Pawn(board.getChessSquare(0, 1), true));
    playerBlack->addPiece(new Pawn(board.getChessSquare(1, 1), true));
    playerBlack->addPiece(new Pawn(board.getChessSquare(2, 1), true));
    playerBlack->addPiece(new Pawn(board.getChessSquare(3, 1), true));
    playerBlack->addPiece(new Pawn(board.getChessSquare(4, 1), true));
    playerBlack->addPiece(new Pawn(board.getChessSquare(5, 1), true));
    playerBlack->addPiece(new Pawn(board.getChessSquare(6, 1), true));
    playerBlack->addPiece(new Pawn(board.getChessSquare(7, 1), true));


    playerWhite->addPiece(new Rook(board.getChessSquare(0, 7), false));
    playerWhite->addPiece(new Knight(board.getChessSquare(1, 7), false));
    playerWhite->addPiece(new Bishop(board.getChessSquare(2, 7), false));
    playerWhite->addPiece(new Queen(board.getChessSquare(3, 7), false));
    playerWhite->addPiece(new King(board.getChessSquare(4, 7), false));
    playerWhite->addPiece(new Bishop(board.getChessSquare(5, 7), false));
    playerWhite->addPiece(new Knight(board.getChessSquare(6, 7), false));
    playerWhite->addPiece(new Rook(board.getChessSquare(7, 7), false));

    playerWhite->addPiece(new Pawn(board.getChessSquare(0, 6), false));
    playerWhite->addPiece(new Pawn(board.getChessSquare(1, 6), false));
    playerWhite->addPiece(new Pawn(board.getChessSquare(2, 6), false));
    playerWhite->addPiece(new Pawn(board.getChessSquare(3, 6), false));
    playerWhite->addPiece(new Pawn(board.getChessSquare(4, 6), false));
    playerWhite->addPiece(new Pawn(board.getChessSquare(5, 6), false));
    playerWhite->addPiece(new Pawn(board.getChessSquare(6, 6), false));
    playerWhite->addPiece(new Pawn(board.getChessSquare(7, 6), false));
}

// Handles game logic when a click occurs to select and move pieces
void Game::handleClick(sf::RenderWindow& window) {
    if (gamePhase == 0) { // Selecting piece to move
        // Set origin square
        origin = board.getClickedSquare(window);
        if (origin == nullptr) { // if no square clicked
            return;
        }
        // Check if clicked square has a piece
        if (origin->getPiece() == nullptr) {
            // case where empty square is clicked; early return for now
            return;
        }
        // Highlight origin square
        origin->setHighlight(true);
        // Change game phase
        gamePhase = 1;
        // Highlight valid moves
        std::vector<Square*> validSquares = board.getValidMoves(origin);
        for (int i = 0; i < validSquares.size(); i++) {
            validSquares[i]->setHighlight(true);
        }

    } else { // Selecting square to move to
        // Set destination square
        destination = board.getClickedSquare(window);
        if (destination == nullptr) { // if no square clicked
            return;
        }
        // Check if user clicked same square
        if (origin == destination) {
            gamePhase = 0; // Go back to piece selection (cancel move)
            origin = nullptr; // Reset origin pointer
            board.unhighlightAll();
            return; // Early return
        }

        // Get valid moves
        std::vector<Square*> validSquares = board.getValidMoves(origin);
        // Check if destination square is in valid moves
        bool valid;
        if (std::find(validSquares.begin(), validSquares.end(), destination) != validSquares.end()) {
            valid = true;
        } else {
            valid = false;
        }
        
        if (!valid) { // if move is invalid i.e non-highlighted square clicked
            return;
        } else { // Move piece
            board.movePiece(origin, destination);
            // Change game phase
            gamePhase = 0;
            // Reset origin and destination pointers
            origin = nullptr;
            destination = nullptr;
            // Un-highlight squares
            board.unhighlightAll();
        }
    }
}

// Returns board
Board* Game::getBoard() {
    return &board;
}

// returns player

Player* Game::getPlayer(int color) {
    if(color == 0) {
        return playerBlack;
    } else {
        return playerWhite;
    }
}

Game::~Game() {
    delete playerWhite;
    delete playerBlack;
}