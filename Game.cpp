#include "Game.h"

Game::Game() {
    gamePhase = 0;
}

void Game::handleClick(sf::RenderWindow& window) {
    if (gamePhase == 0) { // Selecting piece to move
        // Set origin square
        origin = board.getClickedSquare(window);
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
        // Check move validity
        bool valid = board.checkValidMove(origin, destination);
        // Check if user clicked the same square twice or move is invalid
        if ((origin == destination) || !valid) {
            return;
        } else { // Move piece
            board.movePiece(origin, destination);
            // Change game phase
            gamePhase = 0;
            // Un-highlight squares
            board.unhighlightAll();
        }
    }
}

Board* Game::getBoard() {
    return &board;
}