#include <SFML/Graphics.hpp>
#include "game_of_life.h"

int main()
{
    sf::RenderWindow window(
        sf::VideoMode(800, 400),
        "Game of Life"
    );

    window.setFramerateLimit(60);

    game_of_life igra;

    sf::Clock sat;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sat.getElapsedTime().asSeconds() >= 2.f)
        {
            igra.sljedeca_generacija();
            sat.restart();
        }

        window.clear(sf::Color(244, 236, 220));

        igra.iscrtaj(window);

        window.display();
    }

    return 0;
}