#pragma once

#include<vector>

#include<SFML/Graphics.hpp>

#include "CelestialBody.h"

namespace sim
{
	class Universe
	{
		public:
			//List of all bodies
			std::vector<sim::CelestialBody> bodyList;
			
			//Simulation variables
			float timeStep = 0.1f;
			const float G = 6.67e-11f;

			//Adding a new Body
			void AddBody(CelestialBody body);
			
			//Physics
			void CalculatePositions(int subdivisions);
			void CalculateDeltaV(int subdivisions);

			//Drawing planets
			void DrawPlanets(sf::RenderWindow *window, int offsetX, int offsetY, float zoom);
	};
}