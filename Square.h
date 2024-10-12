#ifndef SQUARE_H
#define SQUARE_H

#include "Clickable.h"
#include <SFML/Graphics.hpp>

class Piece;
class Square : public Clickable {
    private:
        // Drawing
        sf::RectangleShape square;
        sf::Color defaultColor;
        sf::Color highlightedColor;

        // Game logic
        Piece* piece;
        sf::Vector2f gridPos;
    public:
        Square();
        
        sf::RectangleShape* getSquare();
        void setColor(sf::Color color);
 
        void setHighlight(bool highlighted);
        void setPosition(sf::Vector2f position);
        void draw(sf::RenderWindow& window);
        void setPiece(Piece* piece);
        void removePiece();
        Piece* getPiece();
        void setGridPos(sf::Vector2f& position);
        sf::Vector2f getGridPos();
};

#endif