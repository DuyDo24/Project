#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

int main()
{   
    //window
    sf::RenderWindow window(sf::VideoMode(500, 500), "Mouse Test Window");

    //circle shape
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    //mouse position
    sf::Vector2i mousePos;

    //font
    sf::Font font;
    font.loadFromFile("arial.ttf");

    //text
    sf::Text mousePosText;
    mousePosText.setFont(font);
    mousePosText.setCharacterSize(20);
    mousePosText.setPosition(100,100);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        mousePos = sf::Mouse::getPosition(window);
        mousePosText.setString("(" + to_string(mousePos.x) + ", " + to_string(mousePos.y) + ")");

        window.clear();
        window.draw(shape);
        window.draw(mousePosText);
        window.display();
    }

    return 0;
}