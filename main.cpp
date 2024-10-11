#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Pawn.h"

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(400, 400), "Chess Game");

    // Create the game board
    Board board;

    // Initialize pawns on the board
    for (int i = 0; i < 8; ++i) {
        board.getChessSquare(i, 1)->setPiece(new Pawn(board.getChessSquare(i, 1), false));  // White pawns
        board.getChessSquare(i, 6)->setPiece(new Pawn(board.getChessSquare(i, 6), true));   // Black pawns
    }

    // Variables for piece movement
    Square* selectedSquare = nullptr;  // To store the currently selected square

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Get the mouse position
                    sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

                    // Determine which square was clicked
                    int x = static_cast<int>(mousePos.x / 50); // Each square is 50 pixels
                    int y = static_cast<int>(mousePos.y / 50);

                    // Check if the clicked square is valid
                    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
                        Square* targetSquare = board.getChessSquare(x, y);

                        // If a square is already selected, attempt to move the piece
                        if (selectedSquare) {
                            if (selectedSquare->getPiece()) {
                                // Validate the move
                                sf::Vector2f start = selectedSquare->getPosition();
                                sf::Vector2f end = targetSquare->getPosition();
                                
                                if (selectedSquare->getPiece()->isValidMove(start, end)) {
                                    board.movePiece(selectedSquare, targetSquare);
                                }
                            }
                            selectedSquare = nullptr; // Deselect the piece after moving
                        } else {
                            // Select the square if it contains a piece
                            selectedSquare = targetSquare->getPiece() ? targetSquare : nullptr;
                        }
                    }
                }
            }
        }

        // Clear the window
        window.clear(sf::Color::Black);

        // Draw the board
        board.drawBoard(window);

        // Display the contents of the window
        window.display();
    }

    // Clean up dynamically allocated pieces
    for (int i = 0; i < 8; ++i) {
        delete board.getChessSquare(i, 1)->getPiece(); // Delete white pawns
        delete board.getChessSquare(i, 6)->getPiece(); // Delete black pawns
    }

    return 0;
}
