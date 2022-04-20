#include <SFML/Graphics.hpp>
#include <iostream>

#include "CelestialBody.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Universe Simulation");

    sim::CelestialBody cb(sf::Vector2f(0, 0), sf::Vector2f(0, 10), 100);

    std::cout << cb.velocity.x << " " << cb.velocity.y << "\n";

    while (window.isOpen()) 
    {
        sf::Event event;

        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}