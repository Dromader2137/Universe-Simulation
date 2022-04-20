#pragma once

#include<SFML/Graphics.hpp>

namespace sim
{
	class CelestialBody
	{
		public:
			sf::Vector2f position;
			sf::Vector2f velocity;
			double mass;

			CelestialBody(sf::Vector2f position, sf::Vector2f velocity, double mass);
	};
}