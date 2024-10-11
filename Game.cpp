#include "Game.h"

Game::Game() {
    gamePhase = 0;
}

void Game::handleClick(sf::RenderWindow& window) {
    if (gamePhase == 0) {
        target = board.getClickedSquare(window);
        gamePhase = 1;
        target->setHighlight(true);
    } else {
        destination = board.getClickedSquare(window);
        if (target == destination) {
            return;
        } else {
            board.movePiece(target, destination);
            gamePhase = 0;
            target->setHighlight(false);
            
        }
        
    }
}

Board* Game::getBoard() {
    return &board;
}