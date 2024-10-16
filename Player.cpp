#include "Player.h"
#include <random>
#include <iostream>
#include<cstdlib>
#include <vector>
#include "Card.h"

Player::Player(int color) {
    this->color = color; 
    for(int i=0;i<3;i++) {
        hand.push_back(nullptr); //creating null ptrs for cards
    }
}

void Player::generateCards(sf::Font &font) {
    int visSize = pieces.size(); //finding size of entire pieces
    std::vector<Piece*> availPieces;
    int availSize;
    bool found = false;
    for(int i=0;i<visSize;i++) {
        found = false;
        availSize = availPieces.size();
        for(int j=0;j<availSize;j++) {
            if(pieces[i]->getName() == availPieces[j]->getName()) { //if pieces match
                found = true; 
            }
        }
        if(!found && pieces[i]->getName() != "King") { //making sure no king cards generate as it is always moveable
            availPieces.push_back(pieces[i]); //this logic only adds types of pieces
        }
    }
    int size = availPieces.size();
    if(size == 0) {
        for(int i=0;i<3;i++) {
            if (hand[i] != nullptr) {
                delete hand[i];  // Free the old Card objects to avoid memory leaks
            }
            hand[i] = nullptr;
        }
    }
    
    srand((unsigned) time(NULL));

    int num;
    int iter;
    found = false;
    if(size >= 4) {
        iter = 3;
    } else {
        iter = size;
    }
    int stored[iter];

    for(int i=0;i<iter;i++) {
        if (hand[i] != nullptr) {
            delete hand[i];  // Free the old Card objects to avoid memory leaks
        }
        num = rand() % size; //generating a random card from available cards
        while(true) {
            found = false;
            for(int j=0;j<3;j++) {
                if(num == stored[j]) {
                    num = rand() % size; //rerunning in order to not get the same card again
                    found = true;
                }
            }
            if(!found) {
                break;
            }
        }

        stored[i] = num;
        //std::cout << num << std::endl;
        hand[i] = new Card(availPieces[num], font, i);
    }
    if(iter < 3) {
        for(int i=iter;i<3;i++){ //making remaining cards null ptrs when the user has below 3 types of pieces
            hand[i] = nullptr;
        }
    }
}

void Player::drawCards(sf::RenderWindow& window) {
    for(int i=0;i<3;i++) {
        if(hand[i] != nullptr) {
            hand[i]->draw(window);
        }
    }
}


Card* Player::getClickedCard(sf::RenderWindow& window) {
    for(int i=0;i<3;i++) {
        if(hand[i] == nullptr) {
            continue;
        } else {
            if(hand[i]->checkClicked(window)) {
                return hand[i];
            };
        }
    }
    return nullptr;
}

std::vector<Piece*> Player::getPieces() {
    return pieces;
}

std::vector<Square*> Player::getValidPieceSquares(Piece *piece) {
    int size = pieces.size();
    std::vector<Square*> validSquares;
    for(int i=0;i<size;i++) {
        if(pieces[i]->getName() == piece->getName()) { //if the vector's piece name matches the piece name
            validSquares.push_back(pieces[i]->getSquare());
        } else if(pieces[i]->getName() == "King") {
            validSquares.push_back(pieces[i]->getSquare()); //Making it so king can always be moved
        }
    }
    return validSquares;
}

std::vector<Piece*> Player::getCapturedPieces() {
    return capturedPieces;
}


void Player::removePiece(Piece *piece){
    int size = pieces.size();
    bool found = false;
    int pos;
    for(int i=0;i<size;i++) {
        if(pieces[i] == piece) {
            found = true;
            pos = i;
        }
    }
    if(found) {
        pieces.erase(pieces.begin()+pos);
    }

    capturedPieces.push_back(piece);
}


void Player::addPiece(Piece *piece) {
    pieces.push_back(piece);
}


void Player::capturePiece(Piece *piece, Player *opponent) {
    opponent->removePiece(piece);
}

Player::~Player() {
    int size = pieces.size();
    for(int i=0;i<size;i++) {
        delete pieces[i];
    }

    size = capturedPieces.size();
    for(int i=0;i<size;i++) {
        delete capturedPieces[i];
    }

}