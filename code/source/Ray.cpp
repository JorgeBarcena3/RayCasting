#include "../headers/Ray.hpp"
#include "../headers/SFML_Window.hpp"
#include "../headers/Map.hpp"

Ray::Ray(vec2f op, float ca, const Map& m, const Player& p) : originalPoint(op), currentAngle(ca), map(&m), player(&p)
{

}

std::vector<std::pair<int, float>> Ray::getIntersections(int w, const SFML_Window* window)
{
	std::vector<std::pair<int, float>> intersections;

	int fixedPosition = w * map->getSize().x / (*window).getSize().x;

	vec2f direction(player->getPosition().x - fixedPosition, player->getPosition().y - fixedPosition);
	direction.normalize();

	vec2f p(player->getPosition().x, player->getPosition().y);

	while (p.y >= 0 && p.y < map->getSize().y)
	{
		Map::MAP_VALUE value = map->getCoordinate((int)p.x, (int)p.y);

		if (value != Map::MAP_VALUE::floor)
		{
			vec2f pd(p);
			pd -= player->getPosition();
			float d = pd.length();
			intersections.push_back(std::pair<int, float>((int)value, p.length()));
		}

		p += direction;

	}

	return intersections;
}
