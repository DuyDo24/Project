#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Game.h"
#include "Player.h"
#include "Card.h"

enum class GameState {
    MENU,
    NEW_GAME,
    RESUME_GAME,
    IN_GAME
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 600), "Card Chess");

    // Load header PNG image
    sf::Texture headerTexture;
    if (!headerTexture.loadFromFile("textures/Card_Chess.png")) {
        return -1;
    }

    // Create a sprite for the header
    sf::Sprite headerSprite;
    headerSprite.setTexture(headerTexture);

    // Scale or resize the header image to fit the window if needed (optional)
    headerSprite.setPosition(0, 0);  // Position the header at the top of the window (adjust for centering)

    // Load font for menu and other text
    sf::Font font;
    if (!font.loadFromFile("Bold & Stylish Calligraphy.ttf")) {
        return -1;
    }

    // Create menu items
    sf::Text newGameText;
    newGameText.setFont(font);
    newGameText.setString("New Game");
    newGameText.setCharacterSize(40); 
    newGameText.setFillColor(sf::Color::Black);
    newGameText.setPosition(100, 300);  

    sf::Text resumeGameText;
    resumeGameText.setFont(font);
    resumeGameText.setString("Resume Game");
    resumeGameText.setCharacterSize(40);  
    resumeGameText.setFillColor(sf::Color::Black);
    resumeGameText.setPosition(70, 400); 

    sf::RectangleShape newGameRect;
    newGameRect.setSize(sf::Vector2f(240, 60));  
    newGameRect.setFillColor(sf::Color(211,211,211)); 
    newGameRect.setOutlineColor(sf::Color::Black);  
    newGameRect.setOutlineThickness(5); 
    newGameRect.setPosition(80, 300); 

    sf::RectangleShape resumeGameRect;
    resumeGameRect.setSize(sf::Vector2f(300, 60));  
    resumeGameRect.setFillColor(sf::Color(211,211,211));  
    resumeGameRect.setOutlineColor(sf::Color::Black);  
    resumeGameRect.setOutlineThickness(5);  
    resumeGameRect.setPosition(50, 400);  

    GameState gameState = GameState::MENU;  // Start with menu state

    Player playerBlack(0);
    Player playerWhite(1);
    Game game;
    Board* board = game.getBoard();
    game.getPlayer(1)->generateCards(font);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (gameState == GameState::MENU) {
                // Handle menu interaction
                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (newGameText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        gameState = GameState::NEW_GAME;
                    } else if (resumeGameText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        gameState = GameState::RESUME_GAME;
                    }
                }
            } else if (gameState == GameState::NEW_GAME || gameState == GameState::RESUME_GAME) {
                // Handle game interaction (existing logic)
                if (event.type == sf::Event::MouseButtonPressed) {
                    game.handleClick(window,font);  // Handle the game click
                }
            }
        }

        window.clear(sf::Color(232,220,202));  // Background color

        if (gameState == GameState::MENU) {
            // Draw header image (Card Chess PNG)
            window.draw(headerSprite);

            // Draw menu
            window.draw(newGameRect);
            window.draw(resumeGameRect);
            window.draw(newGameText);
            window.draw(resumeGameText);
            
        } else if (gameState == GameState::NEW_GAME || gameState == GameState::RESUME_GAME) {
            // Draw game
            game.getPlayer(game.getPlayerTurn())->drawCards(window);
            board->drawBoard(window);
        }

        window.display();
    }

    return 0;
}