#pragma once

#include<SFML/Graphics.hpp>

namespace sim
{
	class CelestialBody
	{
		public:
			sf::Vector2f position;
			sf::Vector2f velocity;
			float mass;

			sf::CircleShape sprite;

			CelestialBody(sf::Vector2f position, sf::Vector2f velocity, float mass, sf::CircleShape sprite);

			void SimulatePosition(float timeStep);
	};
}