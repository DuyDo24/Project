#include <SFML/Graphics.hpp>
#include "Pawn.h"

int main() {
    // Create a window for the game
    sf::RenderWindow window(sf::VideoMode(800, 800), "Card Chess - Display Pawn");

    // Create a pawn and set its initial position
    Pawn whitePawn(sf::Vector2f(350, 350), nullptr);  // The pawn will be placed at (350, 350)

    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear(sf::Color::White);

        // Draw the pawn
        whitePawn.draw(window);  // Call the draw method of the Pawn class

        // Display everything on the window
        window.display();
    }

    return 0;
}
