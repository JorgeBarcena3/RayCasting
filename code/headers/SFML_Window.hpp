// File: SFML_Window.hpp
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


#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include "Scene.hpp"

class SFML_Window
{

private:

	typedef vec2i Size;

	Size size;

	sf::RenderWindow  * renderWindow;

	bool exit;

	Scene scene;

	float rayCounter;

public:

	SFML_Window(int w, int h, std::string name = "SFML TEMPLATE");

	void play();

	inline bool isPlaying() { return !exit; };

	inline Size getSize() const { return size; }


private:

	void configWindow();

	void render();


	

};