#include <SFML/Graphics.hpp>
#include "Clickable.h"

Clickable::Clickable() {
    
}

void Clickable::set_hitbox(const sf::FloatRect& hitbox) {
    this->hitbox = hitbox;
}

sf::FloatRect Clickable::get_hitbox() {
    return getTransform().transformRect(hitbox);
}

bool Clickable::checkClicked(sf::RenderWindow& window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if(this->get_hitbox().contains(mousePos.x, mousePos.y)) {
            return true;
        } else {
            return false;
        }
};
