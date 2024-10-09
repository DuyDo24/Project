#ifndef SQUARE_H
#define SQUARE_H

//#include "Drawable.h"
#include <SFML/Graphics.hpp>

class Square {
    private:
        sf::RectangleShape square;
    public:
        Square();
        sf::RectangleShape* getSquare();
        void setColor(sf::Color color);
        void draw(sf::Vector2f& position, sf::RenderWindow& window);
};

#endif