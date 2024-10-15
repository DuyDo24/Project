#include "Drawable.h"

// Default constructor
Drawable::Drawable() : point(sf::Vector2f(0,0)){}

// Constructor
Drawable::Drawable(const sf::Vector2f& position) : point(position) {}

// Destructor
Drawable::~Drawable() {}

// Method to set the position of the drawable object's image
void Drawable::setPosition(const sf::Vector2f& position) {
    point = position;
    image.setPosition(point);  // SFML's setPosition for Sprite
}

// Method to set the texture of the sprite
void Drawable::setTexture(const sf::Texture& texture) {
    image.setTexture(texture); // SFML's setTexture for Sprite
}

sf::Sprite Drawable::getImage() {
    return image;
}

// Getter for the position
sf::Vector2f Drawable::getPosition() const {
    return point;
}