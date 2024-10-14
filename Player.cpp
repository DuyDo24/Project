#include "Player.h"
#include <random>
#include <iostream>
#include <vector>
#include "Card.h"

Player::Player(int color) {
    this->color = color; 
    for(int i=0;i<3;i++) {
        hand.push_back(nullptr);
    }
}

void Player::generateCards(std::vector<Piece*> pieces, sf::Font &font) {
    int visSize = pieces.size();
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
            availPieces.push_back(pieces[i]);
        }
    }
    int size = availPieces.size();
    
    int num;
    
    for(int i=0;i<3;i++) {
        if (hand[i] != nullptr) {
            delete hand[i];  // Free the old Card object to avoid memory leaks
        }
        num = rand() % size;
        hand[i] = new Card(availPieces[num], font, i);
    }
}

void Player::drawCards(sf::RenderWindow& window) {
    for(int i=0;i<3;i++) {
        hand[i]->draw(window);
    }
}