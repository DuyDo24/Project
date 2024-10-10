#include <SFML/Graphics.hpp>
#include "Clickable.h"


void Clickable::set_hitbox(sf::FloatRect& hitbox) {
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
