#pragma once

#include<SFML/Graphics.hpp>

namespace sim
{
	class CelestialBody
	{
		public:
			//Physics
			sf::Vector2f position;
			sf::Vector2f velocity;
			float mass;

			//Graphics
			sf::CircleShape sprite;

			//Constructor
			CelestialBody(sf::Vector2f position, sf::Vector2f velocity, float mass, sf::CircleShape sprite);
	};
}