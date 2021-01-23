#pragma once
#include"SFML/Graphics.hpp"
class room:
	public sf::RectangleShape
{
public:
	room();
	bool v=false;
	sf::Vector2<float> posi;
	void update();
};

