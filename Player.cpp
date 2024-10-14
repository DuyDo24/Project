#include "Player.h"
#include <random>
#include <iostream>
#include <vector>

#include "Card.h"

Player::Player(int color) {
    this->color = color; 
    this->card = nullptr;
}

void Player::generateCards(std::vector<Piece*> pieces, sf::Font font) {
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
    //font
    //Card newCard(availPieces[0], font, 1);
    if (this->card != nullptr) {
        delete this->card;  // Free the old Card object to avoid memory leaks
    }
    Card newCard = Card(availPieces[0], font, 1);
    this->card = &newCard;
    //this->card = Card(availPieces[0], font, 1);  // Assign the new Card
    //hand[0] = &newCard;
    //for(int i=0;i<3;i++) {
        //num = 0;
        //Card newCard(availPieces[0], font, i);
        //hand.push_back(&newCard);
    //}
}

void Player::drawCards(sf::RenderWindow& window) {
    //for(int i=0;i<3;i++) {
      //  hand[i]->draw(window);
    //}
    if (card == nullptr) {
        std::cerr << "Card is not initialized!" << std::endl;
    } else {
        card->draw(window);  // Ensure this call works
    }
}