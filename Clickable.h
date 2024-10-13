#ifndef CLICKABLE_H
#define ClICKABLE_H

#include <SFML/Graphics.hpp>
#include <string>

class Clickable : public sf::Sprite {
    protected:
        // Rect object used for click detection
        sf::FloatRect hitbox;
    public:
        // Default constructor
        Clickable();
        // Sets hitbox to given rect object
        void set_hitbox(const sf::FloatRect& hitbox);
        // Returns hitbox rect object
        sf::FloatRect get_hitbox();
        // Checks whether mouse is within hitbox rect
        bool checkClicked(sf::RenderWindow& window);
};

#endif