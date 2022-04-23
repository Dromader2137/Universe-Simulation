#include<SFML/Graphics.hpp>

#include "CelestialBody.h"

namespace sim
{
	//Constructor
	CelestialBody::CelestialBody(sf::Vector2f position, sf::Vector2f velocity, float mass, sf::CircleShape sprite)
	{
		this->position = position;
		this->velocity = velocity;
		this->mass = mass;
		this->sprite = sprite;
	}
}