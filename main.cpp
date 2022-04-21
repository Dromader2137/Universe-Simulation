#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <minmax.h>

#include "Universe.h"

int WIDTH = 1280, HEIGTH = 720;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGTH), "Universe Simulation");
    window.setFramerateLimit(60);
    
    
    float zoom = 5e6f; 
    int offsetX = 0, offsetY = 0;

    sim::Universe universe;
    universe.AddBody(sim::CelestialBody(sf::Vector2f(0, 0), sf::Vector2f(0, 0), 6e24f, sf::CircleShape(10)));
    universe.AddBody(sim::CelestialBody(sf::Vector2f(0, 3.844e8f), sf::Vector2f(1025, 0), 7.3e22f, sf::CircleShape(10)));

    while (window.isOpen()) 
    {
        sf::Event event;

        int previousMouseX = 0, previousMouseY = 0;

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
                zoom = max(zoom, (float)0.5);
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
                offsetX += (sf::Mouse::getPosition().x - previousMouseX) / 60;
                offsetY += (sf::Mouse::getPosition().y - previousMouseY) / 60;
                previousMouseX = sf::Mouse::getPosition().x;
                previousMouseY = sf::Mouse::getPosition().y;
            }
        }
        
        window.clear(sf::Color::Black);

        universe.CalculateDeltaV();
        universe.CalculatePositions();
        universe.DrawPlanets(&window, WIDTH / 2 + offsetX, HEIGTH / 2 + offsetY, zoom);
        
        window.display();
    }

    return 0;
}