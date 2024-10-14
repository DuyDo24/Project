#include "Player.h"
#include <random>
#include <iostream>
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
            if(pieces[i]->getName() == availPieces[j]->getName()) {
                found = true; 
            }
        }
        if(!found) {
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
    
    int num;
    
    for(int i=0;i<3;i++) {
        if (hand[i] != nullptr) {
            delete hand[i];  // Free the old Card objects to avoid memory leaks
        }
        num = rand() % size; //generating a random card from available cards
        //std::cout << num << std::endl;
        hand[i] = new Card(availPieces[num], font, i);
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
        if(pieces[i]->getName() == piece->getName()) {
            validSquares.push_back(pieces[i]->getSquare());
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