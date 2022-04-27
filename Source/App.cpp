#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <minmax.h>
#include <time.h>

#include "Universe.h"

//Default window size
int WIDTH = 1280, HEIGTH = 720;
int FPS_CAP = 144;
int FRAME_SUBDIVISIONS = 100;

float random()
{
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

int main()
{
    //Window initialization
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGTH), "Universe Simulation");
    window.setFramerateLimit(FPS_CAP);

    srand(2121);
    
    //Camera movement
    float zoom = 1e4; 
    int offsetX = 0, offsetY = 0;
    int previousMouseX = 0, previousMouseY = 0;
    int currentMouseX = 0, currentMouseY = 0;
    int deltaX = 0, deltaY = 0;

    //FPS Counting
    float fps;
    sf::Clock fpsClock;

    //TEMP: Universe declaration
    sim::Universe universe;
    for (int i = 0; i < 10; ++i)
    {
        universe.AddBody(sim::CelestialBody(sf::Vector2f(random() - 0.5f, random() - 0.5f) * 5e6f, sf::Vector2f(random() - 0.5f, random() - 0.5f) * 10000.0f, (random() + 1.0f) * 1e24f + 1.0f, sf::CircleShape(5.0f)));
    }
    //---

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

                offsetX = (offsetX / delta);
                offsetY = (offsetY / delta);
                zoom *= delta;
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

        //Simulation stuff
        for (int i = 0; i < FRAME_SUBDIVISIONS; ++i)
        {
            universe.CalculateDeltaV(FRAME_SUBDIVISIONS);
            universe.CalculatePositions(FRAME_SUBDIVISIONS);
        }
        universe.DrawPlanets(&window, (WIDTH) / 2 + offsetX , (HEIGTH) / 2 + offsetY, zoom); 
        
        window.display();

        //FPS Counting
        float currentTime = fpsClock.restart().asSeconds();
        fps = 1.0f / currentTime;
        std::cout << "FPS: " << (int)fps << "\n";
    }

    return 0;
}