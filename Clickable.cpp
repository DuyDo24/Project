#include <SFML/Graphics.hpp>
#include "Clickable.h"

// Default constructor
Clickable::Clickable() {
    
}

// Sets hitbox to given rect object
void Clickable::set_hitbox(const sf::FloatRect& hitbox) {
    this->hitbox = hitbox;
}

// Returns hitbox rect object
sf::FloatRect Clickable::get_hitbox() {
    return getTransform().transformRect(hitbox);
}

// Checks whether mouse is within hitbox rect
bool Clickable::checkClicked(sf::RenderWindow& window) {
        // Get cursor position
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        // Check whether mouse contained in hitbox
        if(this->get_hitbox().contains(mousePos.x, mousePos.y)) {
            return true;
        } else {
            return false;
        }
};
