#include "Player.h"
#include <random>
#include <iostream>
#include <vector>

#include "Card.h"

Player::Player(int color) {
    this->color = color; 
    this->card = nullptr;
}

void Player::generateCards(std::vector<Piece*> pieces) {
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
    sf::Font font;
    font.loadFromFile("arial.ttf");
    std::cout << availPieces[0]->getColor() <<std::endl;
    //Card newCard(availPieces[0], font, 1);
    if (this->card != nullptr) {
        delete this->card;  // Free the old Card object to avoid memory leaks
    }
    this->card = new Card(availPieces[0], font, 1);  // Assign the new Card
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
    card->draw(window);
}