#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <minmax.h>

#include "Universe.h"

//Default window size
int WIDTH = 1280, HEIGTH = 720;
int FPS_CAP = 240;

float random()
{
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

int main()
{
    //Window initialization
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGTH), "Universe Simulation");
    window.setFramerateLimit(FPS_CAP);
    
    //Camera movement
    float zoom = 1e4; 
    int offsetX = 0, offsetY = 0;
    int previousMouseX = 0, previousMouseY = 0;
    int currentMouseX = 0, currentMouseY = 0;
    int deltaX = 0, deltaY = 0;

    //TEMP: Universe declaration
    sim::Universe universe;
    for (int i = 0; i < 4; ++i)
    {
        universe.AddBody(sim::CelestialBody(sf::Vector2f(random() - 0.5f, random() - 0.5f) * 1e6f, sf::Vector2f(random() - 0.5f, random() - 0.5f) * 10000.0f, 1e23f, sf::CircleShape(5.0f)));
    }

    //Main game loop
    while (window.isOpen()) 
    {
        sf::Event event;

        while (window.pollEvent(event)) 
        {
            //Checking if closed
            if (event.type == sf::Event::Closed)
                window.close();
            //Resizing handling
            if (event.type == sf::Event::Resized)
            {
                WIDTH = event.size.width;
                HEIGTH = event.size.height;
                window.create(sf::VideoMode(WIDTH, HEIGTH), "Universe Simulation");
                window.setFramerateLimit(FPS_CAP);
            }
            //Zoom handling
            if (event.type == sf::Event::MouseWheelMoved) 
            {
                float delta = -(float)event.mouseWheel.delta / 5;

                delta = 1 + delta;

                offsetX /= delta;
                offsetY /= delta;
                zoom *= delta;

                std::cout << delta << "\n";
            }
        }

        //Camera movement handling
        previousMouseX = currentMouseX;
        previousMouseY = currentMouseY;
        currentMouseX = sf::Mouse::getPosition(window).x;
        currentMouseY = sf::Mouse::getPosition(window).y;
        deltaX = currentMouseX - previousMouseX;
        deltaY = currentMouseY - previousMouseY;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) 
        { 
            offsetX += deltaX;
            offsetY += deltaY;
        }
        
        window.clear(sf::Color::Black);

        //Physical calculations
        universe.CalculateDeltaV();
        universe.CalculatePositions();
        universe.DrawPlanets(&window, (WIDTH + offsetX) / 2, (HEIGTH + offsetY) / 2, zoom); 
        
        window.display();
    }

    return 0;
}