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

void Player::generateCards(std::vector<Piece*> pieces, sf::Font &font) {
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
    
    int num;
    
    for(int i=0;i<3;i++) {
        if (hand[i] != nullptr) {
            delete hand[i];  // Free the old Card objects to avoid memory leaks
        }
        num = rand() % size; //generating a random card from available cards
        hand[i] = new Card(availPieces[num], font, i);
    }
}

void Player::drawCards(sf::RenderWindow& window) {
    for(int i=0;i<3;i++) {
        hand[i]->draw(window);
    }
}