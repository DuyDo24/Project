#ifndef CLICKABLE_H
#define ClICKABLE_H

#include <SFML/Graphics.hpp>
#include <string>

class Clickable : public sf::Sprite {
    private:
        sf::FloatRect hitbox;
    public:
        Clickable();
        void set_hitbox(const sf::FloatRect& hitbox);
        sf::FloatRect get_hitbox();
        bool checkClicked(sf::RenderWindow& window);
};

#endif