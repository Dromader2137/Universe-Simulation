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
			float timeStep = 0.05f;

			void AddBody(CelestialBody body);
	};
}