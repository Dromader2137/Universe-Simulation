#include <SFML/Graphics.hpp>
#include <iostream>
#include<algorithm>

#include "Universe.h"

const int WIDTH = 1280, HEIGTH = 720;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGTH), "Universe Simulation");

    sim::Universe universe;
    universe.AddBody(sim::CelestialBody(sf::Vector2f(0, 0), sf::Vector2f(1, 0), 100, sf::CircleShape(10)));
    universe.AddBody(sim::CelestialBody(sf::Vector2f(100, 0), sf::Vector2f(0, 0), 100, sf::CircleShape(10)));

    while (window.isOpen()) 
    {
        sf::Event event;

        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear(sf::Color::Black);
        for(int i = 0; i < universe.bodyList.size(); ++i)
        {
            universe.bodyList[i].sprite.setPosition(universe.bodyList[i].position.x + WIDTH / 2, -universe.bodyList[i].position.y + HEIGTH / 2);
            window.draw(universe.bodyList[i].sprite);
        }
        for (int i = 0; i < universe.bodyList.size(); ++i)
        {
            universe.bodyList[i].SimulatePosition(universe.timeStep);
        }
        window.display();
    }

    return 0;
}