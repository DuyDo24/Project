#include "Game.h"

Game::Game() {
    gamePhase = 0;
}

void Game::handleClick(sf::RenderWindow& window) {
    if (gamePhase == 0) {
        target = board.getClickedSquare(window);
        gamePhase = 1;
    } else {
        destination = board.getClickedSquare(window);
        if (target == destination) {
            return;
        } else {
            board.movePiece(target, destination);
            gamePhase = 0;
        }
        
    }
}

Board* Game::getBoard() {
    return &board;
}