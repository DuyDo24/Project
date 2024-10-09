#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>

class Drawable {
protected:
    sf::Vector2f point;   // Position of the object
    sf::Sprite image;     // Sprite to display the image

public:
    Drawable(const sf::Vector2f& position);
    virtual ~Drawable();

    void setPosition(const sf::Vector2f& position);
    void setTexture(const sf::Texture& texture);
    sf::Vector2f getPosition() const;

    virtual void draw(sf::RenderWindow& window) const = 0;
};

#endif
