#include<SFML/Graphics.hpp>

#include "Universe.h"

namespace sim
{
	void Universe::AddBody(CelestialBody body)
	{
		this->bodyList.push_back(body);
	}
}