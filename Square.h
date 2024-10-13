#ifndef SQUARE_H
#define SQUARE_H

//#include "Drawable.h"
#include "Clickable.h"
#include <SFML/Graphics.hpp>

class Piece;
class Square : public Clickable {
    private:
        //-- Drawing --//
        // Shape object used for drawing
        sf::RectangleShape square;
        // Color of drawn square when not highlighted
        sf::Color defaultColor;
        // Color of drawn square when highlighted
        sf::Color highlightedColor;

        //-- Game logic --//
        // Associated piece
        Piece* piece;
        // Vector2 representing grid coordinates (0-indexed)
        sf::Vector2f gridPos;
    public:
        // Default constructor
        Square();
        
        //-- Drawing --//

        // Return the square's RectangleShape object
        sf::RectangleShape* getSquare();

        // Set default color of square and set highlighted color to red-shifted version of default color
        void setColor(sf::Color color);
        // Set highlighted status of square (swaps RectangleShape fill color between default/highlighted)
        void setHighlight(bool highlighted);
        // Set position of square's RectangleShape and hitbox
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

        // Sets square's grid position
        void setGridPos(sf::Vector2f& position);
        // Gets square's grid position
        sf::Vector2f getGridPos();
};

#endif