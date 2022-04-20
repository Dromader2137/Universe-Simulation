#include<SFML/Graphics.hpp>

#include "CelestialBody.h"

namespace sim
{
	CelestialBody::CelestialBody(sf::Vector2f position, sf::Vector2f velocity, double mass) {
		this->position = position;
		this->velocity = velocity;
		this->mass = mass;
	}
}