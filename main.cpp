#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <minmax.h>

#include "Universe.h"

int WIDTH = 1280, HEIGTH = 720;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGTH), "Universe Simulation");
    float zoom = 5e6;

    sim::Universe universe;
    universe.AddBody(sim::CelestialBody(sf::Vector2f(0, 0), sf::Vector2f(0, 0), 6e24, sf::CircleShape(10)));
    universe.AddBody(sim::CelestialBody(sf::Vector2f(0, 3.844e8), sf::Vector2f(1025, 0), 7.3e22, sf::CircleShape(10)));

    while (window.isOpen()) 
    {
        sf::Event event;

        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized)
            {
                WIDTH = event.size.width;
                HEIGTH = event.size.height;
                window.create(sf::VideoMode(WIDTH, HEIGTH), "Universe Simulation");
            }
            if (event.type == sf::Event::MouseWheelMoved) {
                zoom += zoom * event.mouseWheel.delta / 5;
                zoom = max(zoom, 0.5);
            }
        }
        
        window.clear(sf::Color::Black);

        universe.CalculateDeltaV();
        universe.CalculatePositions();
        universe.DrawPlanets(&window, WIDTH / 2, HEIGTH / 2, zoom);
        
        window.display();
    }

    return 0;
}