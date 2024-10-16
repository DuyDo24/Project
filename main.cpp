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
#include <iostream>

enum class GameState {
    MENU,
    NEW_GAME,
    RESUME_GAME,
    IN_GAME,
    INFO_PAGE,
    GAME_OVER
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 635), "Card Chess", sf::Style::Titlebar | sf::Style::Close);
    //window.setSize(sf::Vector2u(400, 635)); 

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
    if (!font.loadFromFile("calligraphy.ttf")) {
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
    instructions.setPosition(150, 565);  
    instructions.setString("Select card");

    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(50);
    gameOverText.setFillColor(sf::Color::Black);
    gameOverText.setPosition(70, 250);

    //Pass button
    sf::RectangleShape passTurnRect;
    passTurnRect.setSize(sf::Vector2f(70, 25));   
    passTurnRect.setPosition(165, 600);

    sf::Text passTurnText;
    passTurnText.setFont(font);
    passTurnText.setFillColor(sf::Color::Black);
    passTurnText.setString("Pass");
    passTurnText.setCharacterSize(17);
    passTurnText.setPosition(180,600);

    sf::RectangleShape menuRect;
    menuRect.setSize(sf::Vector2f(70, 25));   
    menuRect.setPosition(30, 600);

    sf::Text menuText;
    menuText.setFont(font);
    menuText.setFillColor(sf::Color::Black);
    menuText.setString("Menu");
    menuText.setCharacterSize(17);
    menuText.setPosition(40,600);


    GameState gameState = GameState::MENU;  // Start with menu state

    Game *game;
    Board* board = game->getBoard();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (gameState == GameState::MENU) {
                // Handle menu interaction
                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (newGameText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        game = new Game(font);
                        board = game->getBoard();
                        gameState = GameState::NEW_GAME;
                    } else if (resumeGameText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        game = new Game(font, true);
                        board = game->getBoard();
                        gameState = GameState::RESUME_GAME;
                    } else if (InfoRect.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        gameState = GameState::INFO_PAGE;
                    }
                } else if (event.type == sf::Event::Closed) {
                    window.close();
                }
            } else if (gameState == GameState::INFO_PAGE) {
                // Handle back to menu interaction
                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (backButtonRect.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        gameState = GameState::MENU;
                    }
                } else if (event.type == sf::Event::Closed) {
                    window.close();
                }

            } else if (gameState == GameState::NEW_GAME || gameState == GameState::RESUME_GAME) {
                // Handle game interaction (existing logic)
                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (passTurnRect.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        game->switchTurn(font);
                    }
                    if (menuRect.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        game->saveGame();
                        gameState = GameState::MENU;  // Go back to main menu
                    }
                    game->handleClick(window,font);  // Handle the game click
                if (game->getGamePhase() == 0) {
                        instructions.setString("Select card");
                    } else if (game->getGamePhase() == 1) {
                        instructions.setString("Select piece");
                    } else if (game->getGamePhase() == 2) {
                        instructions.setString("Select move");
                    }
                if (game->isGameOver()) {
                        gameState = GameState::GAME_OVER;
                        if (game->getPlayerTurn() == 0) {
                            gameOverText.setString("Black Wins!");
                        } else {
                            gameOverText.setString("White Wins!");
                        }
                }   
                } else if (event.type == sf::Event::Closed) {
                        game->saveGame();
                        window.close();
                    }
            } else if (gameState == GameState::GAME_OVER) {
                if (event.type == sf::Event::Closed) {
                        window.close();
                } else if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (backButtonRect.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        gameState = GameState::MENU;
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
            game->getPlayer(game->getPlayerTurn())->drawCards(window);
            board->drawBoard(window);
            if(game->getPlayerTurn() == 0) {
                passTurnRect.setFillColor(sf::Color::White);
                passTurnText.setFillColor(sf::Color::Black);
            } else {
                passTurnRect.setFillColor(sf::Color::Black);
                passTurnText.setFillColor(sf::Color::White);
            }
            window.draw(passTurnRect);
            window.draw(passTurnText);
            window.draw(menuRect);
            window.draw(menuText);
            window.draw(instructions);
            
        } else if (gameState == GameState::INFO_PAGE) {
            // Draw info page
            window.draw(infoPageText);
            window.draw(backButtonRect);
            window.draw(backButtonText); 
        } else if (gameState == GameState::GAME_OVER) {
            window.draw(gameOverText);
            window.draw(backButtonRect);
            window.draw(backButtonText); 
        }

        window.display();
    }

    return 0;
}