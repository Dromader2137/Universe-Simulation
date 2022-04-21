#include <math.h>

#include <SFML/Graphics.hpp>

#include "Universe.h"

namespace sim
{
	void Universe::AddBody(CelestialBody body)
	{
		this->bodyList.push_back(body);
	}

	void Universe::CalculatePositions() {
		for (int i = 0; i < this->bodyList.size(); ++i) {
			this->bodyList[i].position += this->bodyList[i].velocity * this->timeStep;
		}
	}

	void Universe::CalculateDeltaV() {
		for (int i = 0; i < this->bodyList.size(); ++i) {
			sf::Vector2f a = sf::Vector2f(0, 0);

			for (int j = 0; j < this->bodyList.size(); ++j) {
				if (i == j) continue;

				sf::Vector2f deltaPos = this->bodyList[j].position - this->bodyList[i].position;
				float distance = sqrt(pow(deltaPos.x, 2) + pow(deltaPos.y, 2));
				sf::Vector2f normalized = deltaPos / distance;
				float force = this->G * this->bodyList[i].mass * this->bodyList[j].mass / pow(distance, 2);
				a += force * normalized / this->bodyList[i].mass;
			}

			this->bodyList[i].velocity += a * this->timeStep;
		}
	}

	void Universe::DrawPlanets(sf::RenderWindow *window, int offsetX, int offsetY, float zoom) {
		for (int i = 0; i < this->bodyList.size(); ++i) {
			this->bodyList[i].sprite.setPosition(this->bodyList[i].position.x / zoom + offsetX, -this->bodyList[i].position.y / zoom + offsetY);
			window->draw(this->bodyList[i].sprite);
		}
	}
}