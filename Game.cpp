#include "Game.h"
#include <algorithm>

// Creates a default state game (starting position)
Game::Game() {
    gamePhase = 0;
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