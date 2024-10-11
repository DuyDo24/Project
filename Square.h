#ifndef SQUARE_H
#define SQUARE_H

//#include "Drawable.h"
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
        
        //-- Drawing --//

        // Return the square's RectangleShape object
        sf::RectangleShape* getSquare();

        // Set default color of square; automatically sets highlighted color
        void setColor(sf::Color color);
        // Set highlighted status of square (swaps RectangleShape fill color between default/highlighted)
        void setHighlight(bool highlighted);
        // Set position of square's RectangleShape; automatically moves hitbox
        void setPosition(sf::Vector2f position);
        // Draws square and associated piece
        void draw(sf::RenderWindow& window);

        //-- Game logic --//

        // Sets square's associated piece
        void setPiece(Piece* piece);
        // Sets square's associated piece to null
        void removePiece();
        // Returns associated piece
        Piece* getPiece();
};

#endif