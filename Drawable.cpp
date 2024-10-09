#include <SFML/Graphics.hpp>

// Abstract class Drawable
class Drawable {
protected:
    sf::Vector2f point;   // Position of the object
    sf::Sprite image;     // Sprite to display the image

public:
    // Constructor to initialize the position
    Drawable(const sf::Vector2f& position) : point(position) {}

    // Virtual destructor for proper cleanup
    virtual ~Drawable() {}

    // Pure virtual function to be implemented by derived classes
    virtual void draw(sf::RenderWindow& window) const = 0;

    // Set the position of the drawable object
    void setPosition(const sf::Vector2f& position) {
        point = position;
        image.setPosition(point);
    }

    // Set the texture for the sprite
    void setTexture(const sf::Texture& texture) {
        image.setTexture(texture);
    }

    // Get the current position of the drawable object
    sf::Vector2f getPosition() const {
        return point;
    }
};
