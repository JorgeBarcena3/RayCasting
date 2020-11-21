// File: Ray.hpp
// Author: Jorge Bárcena Lumbreras

// © Copyright (C) 2020  Jorge Bárcena Lumbreras

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef RAY_HEADER
#define RAY_HEADER

#include <vector>
#include "Math.hpp"

class SFML_Window;
class Map;
class Player;

class Ray
{
private:

	const Map * map;

	const Player * player;

	vec2f originalPoint;

	float currentAngle;

public:

	Ray(vec2f originalPoint, float currentAngle, const Map& m, const Player& p);

	std::vector<std::pair<int, float>> getIntersections(int w, const SFML_Window * window);
};

#endif
