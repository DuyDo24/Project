#ifndef CLICKABLE_H
#define ClICKABLE_H

#include <SFML/Graphics.hpp>
#include <string>

class Clickable : public sf::Sprite {
    private:
        sf::FloatRect hitbox;
        sf::RenderWindow& window;
    public:
        void set_hitbox(sf::FloatRect& hitbox);
        sf::FloatRect get_hitbox();
        bool checkClicked();
};

#endif