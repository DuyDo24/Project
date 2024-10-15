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
    IN_GAME,
    INFO_PAGE
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
    sf::Font font1;
    if (!font.loadFromFile("Bold & Stylish Calligraphy.ttf")) {
        return -1;
    }
     if (!font1.loadFromFile("times new roman.ttf")) {
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

    sf::Text infoText;
    infoText.setFont(font);
    infoText.setString("Game Info");
    infoText.setCharacterSize(40);  
    infoText.setFillColor(sf::Color::Black);
    infoText.setPosition(100, 500); 

    // Create rectangles around menu items
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

    sf::RectangleShape InfoRect;
    InfoRect.setSize(sf::Vector2f(220, 60));  
    InfoRect.setFillColor(sf::Color(211,211,211)); 
    InfoRect.setOutlineColor(sf::Color::Black);  
    InfoRect.setOutlineThickness(5); 
    InfoRect.setPosition(90, 500); 

    // Text and Back button for the info page
    sf::Text infoPageText;
    infoPageText.setFont(font1);
    infoPageText.setString("                     WELCOME TO CARD CHESS!\n\nCard Chess is a unique twist on traditional chess. The core \n mechanics are similar to regular chess, but with an exciting \n strategic element involving cards. Heres how it works:\n\nMovement with Cards:\n- At the start of each turn, you are dealt three cards.\n-Each card corresponds to a specific type of chess piece.\n-You can only move a piece if you have a card for it in\n your hand.\n\n King Exception:\nYou can always move your King, regardless of the cards in \n your hand.\n- This allows you to protect your King \n\nWinning the game:\n-The objective is to capture your opponents King. \n If your King is captured, you lose the game.\n-Just like in traditional chess, you should aim to defend \n your King while strategically attacking your opponent.");
    infoPageText.setCharacterSize(15);  
    infoPageText.setFillColor(sf::Color::Black);
    infoPageText.setPosition(10, 10); 

    sf::Text backButtonText;
    backButtonText.setFont(font);
    backButtonText.setString("Back");
    backButtonText.setCharacterSize(40);  
    backButtonText.setFillColor(sf::Color::Black);
    backButtonText.setPosition(150, 500);  

    sf::RectangleShape backButtonRect;
    backButtonRect.setSize(sf::Vector2f(120, 60));  
    backButtonRect.setFillColor(sf::Color(211,211,211));  
    backButtonRect.setOutlineColor(sf::Color::Black);  
    backButtonRect.setOutlineThickness(5);  
    backButtonRect.setPosition(140, 500);  

    sf::Text instructions;
    instructions.setFont(font);
    instructions.setCharacterSize(20);
    instructions.setFillColor(sf::Color::Black);
    instructions.setPosition(150, 560);  
    instructions.setString("Select card");

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
                    } else if (InfoRect.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        gameState = GameState::INFO_PAGE;
                    }
                }
            } else if (gameState == GameState::INFO_PAGE) {
                // Handle back to menu interaction
                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (backButtonRect.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        gameState = GameState::MENU;
                    }
                }
            } else if (gameState == GameState::NEW_GAME || gameState == GameState::RESUME_GAME) {
                // Handle game interaction (existing logic)
                if (event.type == sf::Event::MouseButtonPressed) {
                    game.handleClick(window,font);  // Handle the game click
                if (game.getGamePhase() == 0) {
                        instructions.setString("Select card");
                    } else if (game.getGamePhase() == 1) {
                        instructions.setString("Select piece");
                    } else if (game.getGamePhase() == 2) {
                        instructions.setString("Select move");
                    }
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
            window.draw(InfoRect);
            window.draw(infoText);
            window.draw(newGameText);
            window.draw(resumeGameText);
            
            
        } else if (gameState == GameState::NEW_GAME || gameState == GameState::RESUME_GAME) {
            // Draw game
            game.getPlayer(game.getPlayerTurn())->drawCards(window);
            board->drawBoard(window);
            window.draw(instructions);
        } else if (gameState == GameState::INFO_PAGE) {
            // Draw info page
            window.draw(infoPageText);
            window.draw(backButtonRect);
            window.draw(backButtonText);
        }

        window.display();
    }

    return 0;
}
