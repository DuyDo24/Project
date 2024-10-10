#include "Game.h"
#include <iostream>

// Use the parameterized constructor to initialize player1 and player2
Game::Game() 
    : window(sf::VideoMode(800, 800), "Card Chess"), 
      player1(true),  // White player
      player2(false), // Black player
      isGameOver(false) {
    
    // Set the current player to Player 1 (White)
    currentPlayer = &player1;

    // Setup the board with initial piece positions
    board.setupBoard();
}

void Game::run() {
    // Main game loop
    while (window.isOpen()) {
        handleInput();
        update();
        draw();
    }
}

void Game::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        // Handle additional events like mouse clicks for selecting pieces and cards
    }
}

void Game::update() {
    // Update game logic (e.g., piece moves, turn changes)
    // This could include checking for valid moves, determining if the game is over, etc.
}

void Game::draw() {
    // Clear the window with a black color
    window.clear(sf::Color::Black);

    // Draw the board and its pieces
    board.draw(window);

    // Draw additional UI elements like player cards, etc.

    // Display the drawn frame
    window.display();
}
