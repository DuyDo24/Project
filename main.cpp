#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Clickable.h"
using namespace std;

int main() {   
    //window
    sf::RenderWindow window(sf::VideoMode(500, 500), "Mouse Test Window");

    //pawn
    Clickable shape;
    shape.setPosition(100,100);
    sf::Texture square_texture;
    square_texture.loadFromFile("pawn.png");
    shape.setTexture(square_texture);
    shape.set_hitbox({0,0,50,50});

    //font
    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    //text
    sf::Text clickText;
    clickText.setFont(font);
    clickText.setCharacterSize(30);
    clickText.setPosition(300,300);
    clickText.setString("clicked");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left ) {
                if(shape.checkClicked(window)) {
                    std::cout << "click";
                    window.draw(clickText);
                };
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}