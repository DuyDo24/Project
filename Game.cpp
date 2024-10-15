#include "Game.h"
#include <algorithm>
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>

Game::Game() { }
// Creates a default state game (starting position)
Game::Game(sf::Font &font) {
    gamePhase = 0;

    players.push_back(new Player(0));
    players.push_back(new Player(1));


    players[0]->addPiece(new Rook(board.getChessSquare(0, 0), true));
    players[0]->addPiece(new Knight(board.getChessSquare(1, 0), true));
    players[0]->addPiece(new Bishop(board.getChessSquare(2, 0), true));
    players[0]->addPiece(new Queen(board.getChessSquare(3, 0), true));
    players[0]->addPiece(new King(board.getChessSquare(4, 0), true));
    players[0]->addPiece(new Bishop(board.getChessSquare(5, 0), true));
    players[0]->addPiece(new Knight(board.getChessSquare(6, 0), true));
    players[0]->addPiece(new Rook(board.getChessSquare(7, 0), true));
    
    players[0]->addPiece(new Pawn(board.getChessSquare(0, 1), true));
    players[0]->addPiece(new Pawn(board.getChessSquare(1, 1), true));
    players[0]->addPiece(new Pawn(board.getChessSquare(2, 1), true));
    players[0]->addPiece(new Pawn(board.getChessSquare(3, 1), true));
    players[0]->addPiece(new Pawn(board.getChessSquare(4, 1), true));
    players[0]->addPiece(new Pawn(board.getChessSquare(5, 1), true));
    players[0]->addPiece(new Pawn(board.getChessSquare(6, 1), true));
    players[0]->addPiece(new Pawn(board.getChessSquare(7, 1), true));


    players[1]->addPiece(new Rook(board.getChessSquare(0, 7), false));
    players[1]->addPiece(new Knight(board.getChessSquare(1, 7), false));
    players[1]->addPiece(new Bishop(board.getChessSquare(2, 7), false));
    players[1]->addPiece(new Queen(board.getChessSquare(3, 7), false));
    players[1]->addPiece(new King(board.getChessSquare(4, 7), false));
    players[1]->addPiece(new Bishop(board.getChessSquare(5, 7), false));
    players[1]->addPiece(new Knight(board.getChessSquare(6, 7), false));
    players[1]->addPiece(new Rook(board.getChessSquare(7, 7), false));

    players[1]->addPiece(new Pawn(board.getChessSquare(0, 6), false));
    players[1]->addPiece(new Pawn(board.getChessSquare(1, 6), false));
    players[1]->addPiece(new Pawn(board.getChessSquare(2, 6), false));
    players[1]->addPiece(new Pawn(board.getChessSquare(3, 6), false));
    players[1]->addPiece(new Pawn(board.getChessSquare(4, 6), false));
    players[1]->addPiece(new Pawn(board.getChessSquare(5, 6), false));
    players[1]->addPiece(new Pawn(board.getChessSquare(6, 6), false));
    players[1]->addPiece(new Pawn(board.getChessSquare(7, 6), false));

    playerTurn = 1;

    font.loadFromFile("calligraphy.ttf");
    players[1]->generateCards(font);
}

// Create game from saved game state
Game::Game(sf::Font &font, bool saved) {
    // Set game phase
    gamePhase = 0;

    // Create players
    players.push_back(new Player(0));
    players.push_back(new Player(1));

    // Open save file
    std::ifstream saveFile;
    saveFile.open("save.txt");

    // Use default save if a save file does not exist
    if (!saveFile) {
        saveFile.open("default_save.txt");
    }

    // Loop once for each square
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            char pieceChar;
            if (saveFile.get(pieceChar)) { // Get next character in save string
                // Create new piece based on character in string, on square based on loop iterations
                switch (pieceChar) {
                    case 'k':
                        players[0]->addPiece(new King(board.getChessSquare(x, y), true));
                        break;
                    case 'K':
                        players[1]->addPiece(new King(board.getChessSquare(x, y), false));
                        break;
                    case 'q':
                        players[0]->addPiece(new Queen(board.getChessSquare(x, y), true));
                        break;
                    case 'Q':
                        players[1]->addPiece(new Queen(board.getChessSquare(x, y), false));
                        break;
                    case 'r':
                        players[0]->addPiece(new Rook(board.getChessSquare(x, y), true));
                        break;
                    case 'R':
                        players[1]->addPiece(new Rook(board.getChessSquare(x, y), false));
                        break;
                    case 'n':
                        players[0]->addPiece(new Knight(board.getChessSquare(x, y), true));
                        break;
                    case 'N':
                        players[1]->addPiece(new Knight(board.getChessSquare(x, y), false));
                        break;
                    case 'b':
                        players[0]->addPiece(new Bishop(board.getChessSquare(x, y), true));
                        break;
                    case 'B':
                        players[1]->addPiece(new Bishop(board.getChessSquare(x, y), false));
                        break;
                    case 'p':
                        players[0]->addPiece(new Pawn(board.getChessSquare(x, y), true));
                        break;
                    case 'P':
                        players[1]->addPiece(new Pawn(board.getChessSquare(x, y), false));
                        break;
                }
            }
        }
    }
    // Set player turn (last character of save string)
    char turnChar;
    saveFile.get(turnChar);
    std::string turnString;
    turnString.append(1, turnChar);
    playerTurn = stoi(turnString);
    

    players[playerTurn]->generateCards(font);

    // close save file
    saveFile.close();
}

// Saves game state
void Game::saveGame() {
    std::ofstream saveFile("save.txt"); // create save file
    std::string saveData; // create save data string

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            // loop through each square of board
            Square* currentSquare = board.getChessSquare(x, y);
            Piece* currentPiece = nullptr;
            std::string pieceName = "";
            int pieceColor = -1;
            // if piece exists, get name and color
            if (currentSquare->getPiece() != nullptr) {
                currentPiece = currentSquare->getPiece();
                pieceName = currentPiece->getName();
                pieceColor = currentPiece->getColor();
            }
            // append character to save data based on type and color
            // uppercase = white, lowercase = black, letter based on piece
            // if no piece write 0
            char pieceChar;
            if (pieceName == "King") {
                pieceChar = 'k';
            } else if (pieceName == "Queen") {
                pieceChar = 'q';
            } else if (pieceName == "Rook") {
                pieceChar = 'r';
            } else if (pieceName == "Knight") {
                pieceChar = 'n';
            } else if (pieceName == "Bishop") {
                pieceChar = 'b';
            } else if (pieceName == "Pawn") {
                pieceChar = 'p';
            } else {
                pieceChar = '0';
            }

            if (pieceColor == 1) {
                pieceChar = toupper(pieceChar);
            }
            saveData.append(1, pieceChar);
        }
    }
    saveData.append(std::to_string(playerTurn)); // append player turn

    saveFile << saveData;
    saveFile.close();
}

// Handles game logic when a click occurs to select and move pieces
void Game::handleClick(sf::RenderWindow& window, sf::Font& font) {
    if(gamePhase == 0) { // Selecting card
        clickedCard = players[playerTurn]->getClickedCard(window);
        if (clickedCard == nullptr) { // if no card clicked
            return;
        }
        clickedCard->setHighlight(true);
        gamePhase = 1;
        std::vector<Square*> validSquares = players[playerTurn]->getValidPieceSquares(clickedCard->getPiece()); //find valid squares with valid pieces
        //std::cout << validSquares[0] << std::endl;
        validSquares[0]->setHighlight(true);
        for (int i = 0; i < validSquares.size(); i++) { // highlight squares with valid pieces
            validSquares[i]->setHighlight(true);
        }
    } else if (gamePhase == 1) { // Selecting piece to move
        // if card is clicked again
        Card* rePick = players[playerTurn]->getClickedCard(window);
        if(rePick == clickedCard) {
            gamePhase = 0;
            board.unhighlightAll();
            clickedCard->setHighlight(false);
            return;
        }
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
        // Get valid options for pieces
        std::vector<Square*> validSquares = players[playerTurn]->getValidPieceSquares(clickedCard->getPiece());;
        // Check if clicked square is in valid moves
        bool valid;
        if (std::find(validSquares.begin(), validSquares.end(), origin) != validSquares.end()) {
            valid = true;
        } else {
            valid = false;
        }
        
        if (!valid) { // if Square is invalid i.e non-highlighted square clicked
            return;
        } else {
            // Change game phase
            gamePhase = 2;
            // Reset highlights
            board.unhighlightAll();
            // Re-highlight valid moves & origin
            origin->setHighlight(true);
            std::vector<Square*> validSquares = board.getValidMoves(origin);
            for (int i = 0; i < validSquares.size(); i++) {
                validSquares[i]->setHighlight(true);
            }
        }

    } else if(gamePhase == 2) { // Selecting square to move to
        // Set destination square
        destination = board.getClickedSquare(window);
        if (destination == nullptr) { // if no square clicked
            return;
        }
        // Check if user clicked same square
        if (origin == destination) {
            gamePhase = 1; // Go back to piece selection (cancel move)
            origin = nullptr; // Reset origin pointer
            board.unhighlightAll(); // Reset highlights
            std::vector<Square*> squaresWithValidPiece = players[playerTurn]->getValidPieceSquares(clickedCard->getPiece()); // find valid squares with valid pieces
            for (int i = 0; i < squaresWithValidPiece.size(); i++) { // highlight squares with valid pieces
                squaresWithValidPiece[i]->setHighlight(true);
            }
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
            int opp;
            if(destination->getPiece() != nullptr) {
                if(playerTurn == 0) {
                    opp = 1;
                } else {
                    opp = 0;
                }
                players[playerTurn]->capturePiece(destination->getPiece(), players[opp]);
            }

            board.movePiece(origin, destination);
            // Change game phase
            gamePhase = 0;
            switchTurn();
            players[playerTurn]->generateCards(font);
            // Reset origin and destination pointers
            origin = nullptr;
            destination = nullptr;
            clickedCard->setHighlight(false);
            clickedCard = nullptr;
            // Un-highlight squares
            board.unhighlightAll();
        }
    }
}

// Returns board
Board* Game::getBoard() {
    return &board;
}

// returns player

Player* Game::getPlayer(int color) {
    return players[color];
}

int Game::getPlayerTurn() {
    return playerTurn;
}

void Game::switchTurn() {
    if(playerTurn == 0) {
        playerTurn = 1;
    } else {
        playerTurn = 0;
    }
}


void Game::setGamePhase(int phase) {
    gamePhase = phase;
}

Game::~Game() {
    for(int i=0;i<2;i++) {
        delete players[i];
    }
}