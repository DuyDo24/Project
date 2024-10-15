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

    players.push_back(new Player(0));
    players.push_back(new Player(1));


    players[0]->addPiece(new Rook(board.getChessSquare(0, 0), true));
    players[0]->addPiece(new Knight(board.getChessSquare(1, 0), true));
    players[0]->addPiece(new Bishop(board.getChessSquare(2, 0), true));
    players[0]->addPiece(new Queen(board.getChessSquare(3, 0), true));
    players[0]->addPiece(new King(board.getChessSquare(4, 0), true));
    players[0]->addPiece(new Bishop(board.getChessSquare(5, 0), true));
    players[0]->addPiece(new Knight(board.getChessSquare(6, 0), true));
    players[0]->addPiece(new Rook(board.getChessSquare(7, 0), true));
    
    players[0]->addPiece(new Pawn(board.getChessSquare(0, 1), true));
    players[0]->addPiece(new Pawn(board.getChessSquare(1, 1), true));
    players[0]->addPiece(new Pawn(board.getChessSquare(2, 1), true));
    players[0]->addPiece(new Pawn(board.getChessSquare(3, 1), true));
    players[0]->addPiece(new Pawn(board.getChessSquare(4, 1), true));
    players[0]->addPiece(new Pawn(board.getChessSquare(5, 1), true));
    players[0]->addPiece(new Pawn(board.getChessSquare(6, 1), true));
    players[0]->addPiece(new Pawn(board.getChessSquare(7, 1), true));


    players[1]->addPiece(new Rook(board.getChessSquare(0, 7), false));
    players[1]->addPiece(new Knight(board.getChessSquare(1, 7), false));
    players[1]->addPiece(new Bishop(board.getChessSquare(2, 7), false));
    players[1]->addPiece(new Queen(board.getChessSquare(3, 7), false));
    players[1]->addPiece(new King(board.getChessSquare(4, 7), false));
    players[1]->addPiece(new Bishop(board.getChessSquare(5, 7), false));
    players[1]->addPiece(new Knight(board.getChessSquare(6, 7), false));
    players[1]->addPiece(new Rook(board.getChessSquare(7, 7), false));

    players[1]->addPiece(new Pawn(board.getChessSquare(0, 6), false));
    players[1]->addPiece(new Pawn(board.getChessSquare(1, 6), false));
    players[1]->addPiece(new Pawn(board.getChessSquare(2, 6), false));
    players[1]->addPiece(new Pawn(board.getChessSquare(3, 6), false));
    players[1]->addPiece(new Pawn(board.getChessSquare(4, 6), false));
    players[1]->addPiece(new Pawn(board.getChessSquare(5, 6), false));
    players[1]->addPiece(new Pawn(board.getChessSquare(6, 6), false));
    players[1]->addPiece(new Pawn(board.getChessSquare(7, 6), false));

    playerTurn = 1;
}

// Handles game logic when a click occurs to select and move pieces
void Game::handleClick(sf::RenderWindow& window, sf::Font& font) {
    if(gamePhase == 0) {
        clickedCard = players[playerTurn]->getClickedCard(window);
        if (clickedCard == nullptr) { // if no card clicked
            return;
        }
        clickedCard->setHighlight(true);
        gamePhase = 1;
        std::vector<Square*> validSquares = players[playerTurn]->getValidPieceSquares(clickedCard->getPiece()); //find valid squares with valid pieces
        //std::cout << validSquares[0] << std::endl;
        validSquares[0]->setHighlight(true);
        for (int i = 0; i < validSquares.size(); i++) {
            validSquares[i]->setHighlight(true);
        }
    } else if (gamePhase == 1) { // Selecting piece to move
        Card* rePick = players[playerTurn]->getClickedCard(window);
        if(rePick == clickedCard) {
            gamePhase = 0;
            board.unhighlightAll();
            clickedCard->setHighlight(false);
            return;
        }
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
        std::vector<Square*> validSquares = players[playerTurn]->getValidPieceSquares(clickedCard->getPiece());;
        // Check if destination square is in valid moves
        bool valid;
        if (std::find(validSquares.begin(), validSquares.end(), origin) != validSquares.end()) {
            valid = true;
        } else {
            valid = false;
        }
        
        if (!valid) { // if Square is invalid i.e non-highlighted square clicked
            return;
        } else {
            origin->setHighlight(true);
            // Change game phase
            gamePhase = 2;
            // Highlight valid moves
            std::vector<Square*> validSquares = board.getValidMoves(origin);
            for (int i = 0; i < validSquares.size(); i++) {
                validSquares[i]->setHighlight(true);
            }
        }

    } else if(gamePhase == 2) { // Selecting square to move to
        // Set destination square
        destination = board.getClickedSquare(window);
        if (destination == nullptr) { // if no square clicked
            return;
        }
        // Check if user clicked same square
        if (origin == destination) {
            gamePhase = 1; // Go back to piece selection (cancel move)
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
            int opp;
            if(destination->getPiece() != nullptr) {
                if(playerTurn == 0) {
                    opp = 1;
                } else {
                    opp = 0;
                }
                players[playerTurn]->capturePiece(destination->getPiece(), players[opp]);
            }

            board.movePiece(origin, destination);
            // Change game phase
            gamePhase = 0;
            newTurn = true;
            if(playerTurn == 0) {
                playerTurn = 1;
            } else{
                playerTurn = 0;
            }
            players[playerTurn]->generateCards(font);
            // Reset origin and destination pointers
            origin = nullptr;
            destination = nullptr;
            clickedCard->setHighlight(false);
            clickedCard = nullptr;
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
    return players[color];
}

int Game::getPlayerTurn() {
    return playerTurn;
}

Game::~Game() {
    for(int i=0;i<2;i++) {
        delete players[i];
    }
}