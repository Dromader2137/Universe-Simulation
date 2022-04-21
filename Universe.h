#pragma once

#include<vector>

#include<SFML/Graphics.hpp>

#include "CelestialBody.h"

namespace sim
{
	class Universe
	{
		public:
			std::vector<sim::CelestialBody> bodyList;
			
			float timeStep = 5;
			const float G = 6.67e-11f;

			void AddBody(CelestialBody body);

			void CalculatePositions();

			void CalculateDeltaV();

			void DrawPlanets(sf::RenderWindow *window, int offsetX, int offsetY, float zoom);
	};
}