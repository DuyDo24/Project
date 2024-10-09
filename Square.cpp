#include "Square.h"

Square::Square() {
    square.setFillColor(sf::Color::Blue);
    square.setSize(sf::Vector2f(50,50));
    square.setPosition(sf::Vector2f(100,100));
}

void Square::setColor(sf::Color color) {
    square.setFillColor(sf::Color::White);
}

void Square::draw(sf::Vector2f& position, sf::RenderWindow& window) {
    square.setPosition(position);
    window.draw(square);
}

sf::RectangleShape* Square::getSquare() {
    return &square;
}