#include "..\headers\SFML_Window.hpp"
#include "../headers/Ray.hpp"
// File: SFML_Window.cpp
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


SFML_Window::SFML_Window(int w, int h, std::string name) : exit(false)
{
	size = { w,h };
	rayCounter = w;
	renderWindow = new sf::RenderWindow(sf::VideoMode(w, h), name);
	configWindow();

}

void SFML_Window::play()
{

	do
	{
		sf::Event event;

		while (renderWindow->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				exit = true;
				break;
			}
			}

			renderWindow->clear();
			render();
			renderWindow->display();
		}

	} while (!exit);
}

void SFML_Window::configWindow()
{
	renderWindow->setVerticalSyncEnabled(true);

}

void SFML_Window::render()
{
	
	float minAngle = scene.getPlayer().getRotation() - scene.getPlayer().fovHalf;

	float angleStep = scene.getPlayer().fov / rayCounter;

	for (int i = 0, currentAngle = minAngle; i < rayCounter; i++, currentAngle += angleStep)
	{
		Ray ray(scene.getPlayer().getPosition(), currentAngle, scene.getMap(), scene.getPlayer());
		ray.getIntersections(i, this);
	}


}
